
import Data.Time.Clock (getCurrentTime, diffUTCTime)
import Text.Printf (printf)

-- Define the Node and LinkedList data structures
data Node = Node Int (Maybe Node)
newtype LinkedList = LinkedList (Maybe Node)

-- Create an empty list
emptyList :: LinkedList
emptyList = LinkedList Nothing

-- Insert at the head
insertHead :: Int -> LinkedList -> LinkedList
insertHead val (LinkedList headNode) = LinkedList (Just (Node val headNode))

-- Search for a value in the list
search :: Int -> LinkedList -> Bool
search _ (LinkedList Nothing) = False
search val (LinkedList (Just (Node dataVal nextNode)))
  | val == dataVal = True
  | otherwise = search val (LinkedList nextNode)

-- Traverse the list and print elements
traverseList :: LinkedList -> IO ()
traverseList (LinkedList Nothing) = putStrLn "End of list"
traverseList (LinkedList (Just (Node val nextNode))) = do
    putStr (show val ++ " ")
    traverseList (LinkedList nextNode)

-- Example usage
main :: IO ()
main = do
    -- Create a linked list and insert 10000 elements
    let list = foldr insertHead emptyList [1..30000]

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