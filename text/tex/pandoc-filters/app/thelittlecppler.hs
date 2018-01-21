-- app/thelittlecppler.hs
import Text.Pandoc.JSON
import Text.Printf (printf)
import Data.Maybe
import Data.Monoid ((<>))

main :: IO ()
main = toJSONFilter (\format (Pandoc meta blocks)-> Pandoc meta $ processBlocks format blocks)

processBlocks :: Maybe Format -> [Block] -> [Block]
processBlocks format_m = processBlocks' 0
  where
    processBlocks' _ [] = []
    processBlocks' n (HorizontalRule:blocks) = minipager True n blocks
    processBlocks' n (OrderedList    attrs blkss:blocks) = OrderedList attrs (fmap (processBlocks' n) blkss) : processBlocks' n blocks
    processBlocks' n (BulletList     blkss      :blocks) = BulletList (fmap (processBlocks' n) blkss) : processBlocks' n blocks
    processBlocks' n (DefinitionList blkss      :blocks) = DefinitionList (fmap ((fmap.fmap) (processBlocks' n)) blkss) : processBlocks' n blocks
    processBlocks' n (Div            attrs blks :blocks) = Div attrs (processBlocks' n blks) : processBlocks' n blocks
    processBlocks' n (b:blocks) = b : processBlocks' n blocks

    --Creating two columns with a minipager inside each of them
    minipager :: Bool -> Integer -> [Block] -> [Block]
    minipager first n = parts1 []
      where parts1 :: [Block] -> [Block] -> [Block]
            parts1 left (Para [Str "=",Space,Str "=",Space,Str "="]:blocks)
              = parts2 left [] blocks
            parts1 left (HorizontalRule:blocks)
              = (if first then HorizontalRule else simpleRule) : left <> minipager False n blocks
            parts1 left (cb@(CodeBlock (id_, classes, namevals) code): blocks)
              = if (isJust . lookup "layout" $ namevals) && (isNothing . lookup "numid" $ namevals)
                   then parts1 (left <> [CodeBlock (id_, classes, ("numid", num_id):namevals) code]) blocks
                   else parts1 (left <> [cb]) blocks
            parts1 left (b:blocks) = parts1 (left<>[b]) blocks
            parts1 left [] = simpleRule : left

            parts2 :: [Block] -> [Block] -> [Block] -> [Block]
            parts2 left right (HorizontalRule:blocks)
              = (simpleRule : columnBegin : left) <> (columnMiddle : right) <> (columnEnd : minipager False (n+1) blocks)
            parts2 left right blocks@(Header{} : _)
              = (simpleRule : columnBegin : left) <> (columnMiddle : right) <> (columnEnd : processBlocks' (n+1) blocks)
            parts2 left right (cb@(CodeBlock (id_, classes, namevals) code): blocks)
              = if ("output" `elem` classes) && (isNothing . lookup "numid" $ namevals)
                   then parts2 left (right <> [CodeBlock (id_, classes, ("numid", num_id):namevals) code]) blocks
                   else parts2 left (right <> [cb]) blocks
            parts2 left right (b:blocks) = parts2 left (right<>[b]) blocks
            parts2 left right []
              = (simpleRule : columnBegin : left) <> (columnMiddle : right) <> [columnEnd]

            num_id = printf "%03d" n
            (columnBegin, columnMiddle, columnEnd, simpleRule)
              = case format_m of
                  Just format@(Format "latex")
                    -> (RawBlock format ("\\begin{minipage}{\\linewidth}"
                                      <> "\\noindent\n"
                                      <> "{\\tiny "<> num_id <>".}\\\\\n"
                                      <> "\\begin{minipage}[t]{.485\\linewidth}"),
                        RawBlock format ("\\end{minipage}\n"
                                      <> "\\hfill\n"
                                      <> "\\begin{minipage}[t]{.485\\linewidth}"),
                        RawBlock format ("\\end{minipage}\n"
                                      <> "\\end{minipage}\n"),
                        RawBlock format "\\vspace{2mm}\\noindent\\hrulefill{}")
                  _ -> (Null, Null, Null, HorizontalRule)
