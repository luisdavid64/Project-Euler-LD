
{-
    We want a large n, with small totient function, we know:

        n/totient(p) = 1/(some product I cant write)

-}

primes :: [Int]
primes = sieve (2: [3,5..])
    where
        sieve (p:xs) = p : sieve [x|x<-xs, x `mod` p > 0]

foldlWhile :: [Int] ->  Int -> (Int -> Bool) -> Int
foldlWhile [] accum f = accum
foldlWhile (x:xs) accum f = let newAccum = accum * x in if f newAccum then foldlWhile xs newAccum f else accum 


main :: IO()
main = do
    x <- getLine
    let max = (read x :: Int); 
    print $ foldlWhile primes 1 (\x -> (x < max))