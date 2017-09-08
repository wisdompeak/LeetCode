### 342.Power-of-Four

满足power of 4的条件是：1.大于零；2.是power of 2；3.num-1之后是3的倍数。

其中满足power of 2的条件是：除了最高bit位是1，其余位都是0，所以 num & (num-1) ==0
