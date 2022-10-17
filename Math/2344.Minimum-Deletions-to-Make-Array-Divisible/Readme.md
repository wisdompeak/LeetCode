### 2344.Minimum-Deletions-to-Make-Array-Divisible

非常直观。要numsDivide里面所有的元素都能整除x，充要条件就是`gcd(numsDivide)`也能整除x。所以我们将nums里面所有小于gcd的元素拿走即可。
