--Smallest feasible number is 44555
--Upper bound is 9^5*5
nums = [11..354259]

--Gives the digit of a number
digs :: Int -> [Int]
digs 0 = []
digs n = digs (n `div` 10) ++ [n `mod` 10]

--Get the sum of digits^5
powSum :: Int -> Int
powSum = (sum . map (^5) . digs) 

--Solve!
p30 :: [Int] -> Int
p30 [] = 0
p30 (x:xs)  
  | powSum x == x = (p30 xs) + x
  | otherwise = p30 xs 

main = do
    let x = p30 nums 
    print x
    return ()