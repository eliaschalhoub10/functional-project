import Data.Time.Clock (getCurrentTime, diffUTCTime)
import Text.Printf (printf)

-- Define a functional list as a wrapper around a Haskell list
newtype List a = List [a]

-- Create an empty list
emptyList :: List a
emptyList = List []

-- Insert an element at the end
insertEnd :: a -> List a -> List a
insertEnd val (List xs) = List (xs ++ [val])

-- Search for an element
search :: Eq a => a -> List a -> Bool
search val (List xs) = val `elem` xs

-- Traverse the list
traverseList :: Show a => List a -> IO ()
traverseList (List xs) = putStrLn $ unwords (map show xs)

-- Example usage
main :: IO ()
main = do
    let list = foldr insertEnd emptyList [1..30000]

    -- Measure time to search for an element
    startSearch <- getCurrentTime
    print $ search 5000 list
    endSearch <- getCurrentTime
    printf "Time taken for search: %.6f seconds\n" (realToFrac (diffUTCTime endSearch startSearch) :: Double)

    -- Measure time to traverse the list
    startTraverse <- getCurrentTime
    traverseList list
    endTraverse <- getCurrentTime
    printf "Time taken for traversal: %.6f seconds\n" (realToFrac (diffUTCTime endTraverse startTraverse) :: Double)
