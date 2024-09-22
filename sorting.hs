-- Tools used: Visual Studio Code, Discord, GitHub, C, Haskell, GeeksForGeeks.org, ChatGPT


quickSort :: Ord a => [a] -> [a]          -- quick sort a list in Haskell
quickSort[] = []
quickSort(x:xs) = quickSort lo ++ [x] ++ quickSort hi
    where
        lo = filter (<=x) xs
        hi = filter (>x) xs


merge :: Ord a => [a] -> [a] -> [a]
merge left [] = left
merge [] right = right
merge (x:xs) (y:ys)
 | x <= y        = x: merge xs (y:ys)     -- if x is smaller than or equal to y, add to result
 | otherwise     = y: merge (x:xs) ys     -- and continue otherwise add y and continue

mergeSort :: Ord a => [a] -> [a]          -- merge sort a list in Haskell
mergeSort[] = []
mergeSort[x] = [x]
mergeSort x = merge (mergeSort leftside) (mergeSort rightside)
    where
        midpt = length x `div` 2
        leftside = take midpt x             -- takes the first half of x
        rightside = drop midpt x            -- drops the first half of x

main :: IO ()
main = do
    -- quicksort testcases
    let testcase1 = [10, 7, 8, 9, 1, 5]
    let sortedlist1 = quickSort testcase1

    let testcase2 = [8, 3, 4, 1, 10, 5, 4];
    let sortedlist2 = quickSort testcase2

    let testcase3 = [31, 20, 49, 11, 44, 99, 8];
    let sortedlist3 = quickSort testcase3

    let testcase4 = [0];                    -- an empty or null array or invalid type results in 
    let sortedlist4 = quickSort testcase4   -- code not compiling. 0 is a placeholder for these cases


    -- mergesort testcases
    let testcase5 = [10, 7, 8, 9, 1, 5];
    let sortedlist5 = mergeSort testcase5
    
    let testcase6 = [4, 9, 8, 3, 11, 1, 2];
    let sortedlist6 = mergeSort testcase6

    let testcase7 = [22, 99, 7, 53, 67, 30, 2];
    let sortedlist7 = mergeSort testcase7

    let testcase8 = [0];                    -- an empty or null array or invalid type results in 
    let sortedlist8 = mergeSort testcase8   -- code not compiling. 0 is a placeholder for these cases
    

    putStrLn "Testcase 1:"
    print testcase1
    putStrLn "Quick Sort 1:"
    print sortedlist1

    putStrLn "Testcase 2:"
    print testcase2
    putStrLn "Quick Sort 2:"
    print sortedlist2

    putStrLn "Testcase 3:"
    print testcase3
    putStrLn "Quick Sort 3:"
    print sortedlist3

    putStrLn "Testcase 4:"
    print testcase4
    putStrLn "Quick Sort 4:"
    print sortedlist4

    putStrLn "Testcase 5:"
    print testcase5
    putStrLn "Merge Sort 1:"
    print sortedlist5

    putStrLn "Testcase 6:"
    print testcase6
    putStrLn "Merge Sort 2:"
    print sortedlist6

    putStrLn "Testcase 7:"
    print testcase7
    putStrLn "Merge Sort 2:"
    print sortedlist7
    
    putStrLn "Testcase 8:"
    print testcase8
    putStrLn "Merge Sort 4:"
    print sortedlist8

