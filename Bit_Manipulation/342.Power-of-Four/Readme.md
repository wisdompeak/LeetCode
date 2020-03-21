### 342.Power-of-Four

满足power of 4的条件是：1.大于零；2.是power of 2；3.num-1之后是3的倍数。

其中满足power of 2的条件是：除了最高bit位是1，其余位都是0，所以 num & (num-1) ==0

为什么num-1一定会是3的倍数呢？(4^k-1)=(2^k+1)(2^k-1)，其中2^k一定不能被3整除，余数可能是1，也可能是2，无论哪一种，(2^k+1)和(2^k-1)里必然有一个能被3整除。


[Leetcode Link](https://leetcode.com/problems/power-of-four)