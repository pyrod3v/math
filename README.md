# math

## fib
**Outputs the fibonacci of the provided number, utilizing the GMP library to support huge values.**

## sqr
**Blazingly fast square number generator.**  
Computes 10,000 values in ~38 microseconds, if `nums[i - j] = x;` is removed it takes less than 1 μs (clock() doesn't have nanosecond precision)  
There is also a SIMD version that can compute them in around 23 μs.