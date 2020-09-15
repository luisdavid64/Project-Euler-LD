--Checks whether number is a palindrome
isPalindrome :: Integer -> Bool
isPalindrome i = i == (read . reverse . show) i
 
-- Checks whether a number is a lychrel number
-- Constraint: if 50 iterations pass and the produced number is not a palindrome,
-- The number is discarded
isLychrel :: Integer -> Integer -> Bool
isLychrel 0 _ = True
isLychrel x y = let val = (y + (read . reverse . show) y ) :: Integer in 
    case isPalindrome val of
        True -> False
        False -> isLychrel (x-1) val

p55 :: Integer -> Int
p55 mx= sum $ map fromEnum (map (isLychrel 50) [1 .. mx])

main = do 
    input <- getLine
    let x = (read input :: Integer)
    print $ p55 x