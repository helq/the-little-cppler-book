-- app/runcppcode.hs
{-# LANGUAGE LambdaCase #-}

import Text.Pandoc.JSON (toJSONFilter)
import Text.Pandoc (Block(CodeBlock))
import System.Directory (getCurrentDirectory)
import System.FilePath ((</>),(<.>))
import System.IO (hPutStr, stderr)
import Data.Maybe (fromMaybe)
import Development.Shake (shake, shakeOptions, shakeVerbosity, Rules, Stdouterr(Stdouterr), Stdout(Stdout),
                          Verbosity(Silent), want, (%>), need, cmd, writeFile')
import Development.Shake.FilePath ((-<.>), exe)
import Data.Monoid ((<>))
import System.Environment (getArgs)
import Control.Monad.IO.Class (liftIO)

doInclude :: String -> Block -> IO Block
doInclude currentDir cb@(CodeBlock (_, classes, namevals) contents) =
  case lookup "layout" namevals of
       Just f -> do
         file_layout <- readFile $ currentDir </> "code" </> "layouts" </> f
         let newcontent = unlines . fmap insertContent . lines $ file_layout
             num_id = fromMaybe "999" $ lookup "numid" namevals
             cpp_name = num_id <> "-code-autogenerated.cc"

         shake shakeOptions{shakeVerbosity=Silent} $
           compile currentDir cpp_name newcontent norun

         return cb
       Nothing -> return cb

  where
    contents' = lines contents
    (includes, mainbody) = if "..." `elem` contents'
                              then let (ics, mainc) = break ("..."==) contents'
                                    in (ics, tail mainc)
                              else ([], contents')

    insertContent line = case break (/= ' ') line of
                           -- TODO: modify so unlines doesn't put a newline at the end of the last line
                           (spaces, "---<<<") -> unlines $ fmap (spaces<>) includes
                           (spaces, "===<<<") -> unlines $ fmap (spaces<>) mainbody
                           _                  -> line
    norun = "norun" `elem` classes

doInclude _ x = return x

compile :: FilePath -> FilePath -> String -> Bool -> Rules ()
compile currentDir cpp_name_ content norun = do
  let cpp_name = currentDir </> "code" </> cpp_name_
      cpp_out  = cpp_name -<.> "out"
      codeDir  = currentDir </> "code"
      wantFiles = if norun then [cpp_name] else [cpp_name, cpp_out]
  --liftIO . hPutStrLn stderr $ normalise cpp_name
  --liftIO $ hPutStrLn stderr cpp_bin
  want wantFiles

  (codeDir </> "*.out") %> \out -> do
    let bin = out -<.> "bin" <.> exe
    need [bin]
    Stdout output <- cmd [bin]
    writeFile' out output

  (codeDir </> "*.cc") %> \out ->
    writeFile' out content

  (codeDir </> "*.bin" <.> exe) %> \out -> do
    let incpp = out -<.> "cc"
    --liftIO . hPutStrLn stderr $ "HEY!"
    need [incpp]
    Stdouterr output <- cmd "clang++" [incpp] ["-o", out]
    liftIO . hPutStr stderr $ output


main :: IO ()
main = do
  currentDir <- getArgs >>= \case
                               (dir:_) -> pure dir
                               _       -> getCurrentDirectory

  --hPrint stderr currentDir
  toJSONFilter (doInclude currentDir)
