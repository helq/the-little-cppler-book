-- maker-src/thelittlecppler.hs
{-# LANGUAGE LambdaCase #-}

import Development.Shake (shakeOptions, shakeArgs, shakeFiles, shakeThreads,
                          need, readFile', (%>), writeFileChanged, writeFile',
                          getDirectoryFiles, newCache, phony, putNormal,
                          removeFilesAfter, want, doesFileExist)
import Development.Shake.Command (Stdout(Stdout), CmdOption(Stdin, FileStdin),
                                  cmd, cmd_)
import Development.Shake.FilePath ((</>), (-<.>), (<.>), exe)
--import Development.Shake.Util ()
import Data.Monoid ((<>))
import Data.Maybe (fromMaybe)
--import Data.Either.Combinators (fromRight)
import Text.Pandoc (readJSON, def, Block(CodeBlock))
import Text.Pandoc.Error (PandocError)
import Text.Pandoc.Walk (query)
import Data.Text (pack)

main :: IO ()
main = shakeArgs shakeOptions{shakeFiles="_build", shakeThreads=4} $ do
    want ["the_little_cppler.pdf"]
    --want ["_build//cpp_book.json"]

    phony "clean" $ do
        putNormal "Cleaning files in _build"
        removeFilesAfter "_build" ["//*"]

    -- this cache is used to read "_build//cpp_book-no-output.json" only once
    cachedReadCpps <- newCache $ \file -> do
        content <- readFile' file
        pure . getCppsOrThrow $ extractCpps content

    readCppFile <- newCache $ \cppFile -> do
        let no_output = "_build//cpp_book-no-output.json"
        need [no_output]

        -- Loading all cpps
        cpp_files <- cachedReadCpps no_output
        -- todo: add exception when there is no cpp (which is weird)
        pure $ case filter ((cppFile==) . fileNameCpp) cpp_files of
                 (cpp:_) -> cpp
                 _       -> error $ "There is for some reason no file `" <> show cppFile <> "` inside the code O_o"

    "the_little_cppler.pdf" %> \out -> do
        let finaljsonpath = "_build//cpp_book.json"
            tex_header = "00-header.tex"
            template = "booktemplate.latex"
        need [tex_header, finaljsonpath, template]
        cmd_ "pandoc" "--template" template
                      "-f json"
                      "--standalone"
                      "--pdf-engine xelatex"
                      "-H" tex_header
                      finaljsonpath
                      --"-t latex"
                      "-o" [out]

    "_build//cpp_book.json" %> \out -> do
        let no_output = "_build//cpp_book-no-output.json"
        need [no_output]

        output_cpps <- cachedReadCpps no_output

        -- Looking for all .out files required to be put inside the json (loadcodeinoutput-exe does that, it inputs all code that has type `output`)
        let -- all cpps must be saved
            outs_cpp = fileNameCpp <$> output_cpps
            -- only the cpp without `norun` should be executed
            outs_bin = fmap (\cpp -> fileNameCpp cpp -<.> "out") . filter (not . doNotRun . optionsCpp) $ output_cpps
        --liftIO $ print outs_bin
        need $ outs_cpp <> outs_bin

        Stdout finaljson <- cmd (FileStdin no_output) "loadcodeinoutput-exe . latex"
        writeFile' out finaljson

    "_build//cpp_book-no-output.json" %> \_ -> do
        let no_output = "_build//cpp_book-no-output.json"
        mds <- getDirectoryFiles "" ["//*-*.md"]
        let input_files = "00-metadata.yaml" : mds

        devel <- doesFileExist "devel"

        -- Creating json from markdown files with the special formating of the little ccpler
        need input_files
        Stdout pre <- cmd "pandoc" "-t json -o -"
                                   input_files
                                   (if devel then "--metadata devel" else "")
        Stdout formated <-
            cmd (Stdin pre) "tlcppler-exe latex" -- important to add "latex"
        writeFile' no_output formated

    ("code" </> "*.flags") %> \out -> do
        let incpp = out -<.> "cc"
        cpp <- readCppFile incpp
        let flags = fromMaybe "" . compilerFlags $ optionsCpp cpp
        --liftIO . putStrLn $ "it's me (alone): " <> show out
        writeFileChanged out flags

    ("code" </> "*.cc") %> \out -> do
        cpp <- readCppFile out
        layout <- readFile' (layoutCpp cpp)
        let contents = applyLayout layout cpp
        --liftIO . putStrLn $ "it's me (alone): " <> show out
        writeFileChanged out contents

    ("code" </> "*.out") %> \out -> do
        let bin = out -<.> "bin" <.> exe
        need [bin]
        Stdout output <- cmd [bin]
        writeFileChanged out output

    ("code" </> "*.bin" <.> exe) %> \out -> do
        let incpp = out -<.> "cc" -- TODO: correct! This will probably fail in windows where an extra ".exe" is at the end of the file
            flagsfile = out -<.> "flags"
        need [incpp, flagsfile]
        --liftIO . hPutStrLn stderr $ "HEY! me here"

        flags <- readFile' flagsfile
        cmd_ "clang++" [incpp] ["-o", out] flags

-- todo: improve exception handling
getCppsOrThrow :: Either PandocError [Cpp] -> [Cpp]
getCppsOrThrow =
  \case
    Left p  -> error $ "Something wrong with `_build//cpp_book-no-output.json` happened\n" <> show p
    Right x -> x


data Cpp = Cpp
  { fileNameCpp :: FilePath
  , layoutCpp   :: FilePath
  , contentCpp  :: String
  , optionsCpp  :: OptionsCpp
    --classesCpp  :: [String],
    --namevalsCpp :: [(String,String)]
  }
  deriving (Show, Read)

data OptionsCpp = OptionsCpp
  { doNotRun :: Bool
  {-, hidden   :: Bool-}
  , compilerFlags :: Maybe String
  }
  deriving (Show, Read)

extractCpps :: String -> Either PandocError [Cpp]
extractCpps json = do
    file <- readJSON def (pack json)
    return $ query extractCppCodeBlock file

  where
    extractCppCodeBlock :: Block -> [Cpp]
    extractCppCodeBlock (CodeBlock (_, classes, namevals) contents) =
      case lookup "layout" namevals of
      Just layout -> [Cpp cppFile layout' contents options]
        -- improve num_id algorithm when a no `numid` is available (eg, hash of contents)
        where num_id = fromMaybe "999" $ lookup "numid" namevals
              cppFile = "code" </> num_id <> "-code-autogenerated.cc"
              layout' = "code" </> "layouts" </> layout
              options = OptionsCpp {
                          doNotRun = ("norun" `elem` classes),
                          --hidden = ("hidden" `elem` classes),
                          compilerFlags = lookup "flags" namevals
                        }
      Nothing -> []
    extractCppCodeBlock _ = []

--fromRight :: b -> Either a b -> b
--fromRight r (Left _)  = r
--fromRight _ (Right r) = r

applyLayout :: String -> Cpp -> String
applyLayout layout contents = unlines . fmap insertContent . lines $ layout
  where
    contents' = lines $ contentCpp contents
    (includes, mainbody) = if "..." `elem` contents'
                              then let (ics, mainc) = break ("..."==) contents'
                                    in (ics, tail mainc)
                              else ([], contents')

    insertContent line = case break (/= ' ') line of
                           -- TODO: modify so unlines doesn't put a newline at the end of the last line
                           (spaces, "---<<<") -> unlines $ fmap (spaces<>) includes
                           (spaces, "===<<<") -> unlines $ fmap (spaces<>) mainbody
                           _                  -> line
