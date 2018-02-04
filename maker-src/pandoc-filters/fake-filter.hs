-- I use this for debugging, to see what certain argument from pandoc gives me

import System.Environment (getArgs)
import Data.Monoid ((<>))

main = do
  args <- getArgs
  all <- getContents :: IO String
  putStr all
  writeFile "_build/test.txt" $ "Args: " <> show args <> "\n" <> all
