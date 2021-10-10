### 2033.Minimum-Operations-to-Make-a-Uni-Value-Grid

首先，满足最终结果的前提条件是，所有矩阵元素与最小值之间的差值必须都是x的倍数。

其次，满足了上面的条件之后，那么这个uni-value是什么呢？我们希望所有元素变换成uni-value的操作总数最小，也就是希望这个uni-value能和大家都“接近”。将这个操作总数乘以x后不难发现，也就是希望这个uni-value到所有元素的距离之和最小。显然，和```296.Best-Meeting-Point```一样的数学结论，这个数一定是所有元素的中位数(median)。

此题的进阶版有：```1703.Minimum-Adjacent-Swaps-for-K-Consecutive-Ones```, ```1478.Allocate-Mailboxes```
