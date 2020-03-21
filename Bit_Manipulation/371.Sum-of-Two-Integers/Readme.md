### 371.Sum-of-Two-Integers

将a+b改造为m+n，其中m=a^b不进位的加法，n=(a&b)<<1将有进位的bit置为1。反复这样的操作直至所有的进位为零，得到的m即为结果。


[Leetcode Link](https://leetcode.com/problems/sum-of-two-integers)