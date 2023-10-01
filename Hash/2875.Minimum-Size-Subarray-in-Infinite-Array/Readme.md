### 2875.Minimum-Size-Subarray-in-Infinite-Array

很显然，任何一个subarray，都可以表示成“nums的某个后缀 + 若干个重复的nums + nums的某个前缀”。

我们将nums重复一遍（长度变成2n）之后，上述的subarray sum就是：`nums[i:j] + k * total`. 其中total是nums[0:n-1]之和。[i:j]是在[0:2n-1]上的一个子区间。k是某个整数（可以是0）.

当我们遍历j的位置，考察某个j时，期望 `presum[j]-presum[i-1]+k*total = target`，转换一下就是`presum[i-1] = presum[j] - target + k*total`。显然，为了使这个式子有解，充要条件就是`presum[i-1]`和`presum[j] - target`关于total同余，并且需要i<j且i越大越好。

所以我们用hash表记录下nums的前缀和关于total的余数，对于每种余数我们都取最新的位置。这样对于任何的j，我们都可以找到对应的最大的i，继而算出k。那么该subarray就是`j-(i-1)+k*n`. 遍历所有的j之后取全局最小值。当然本题也有可能无解，即所有的j都找不到对应的i。

注意，`presum[j] - target`极有可能是负数，所有它取模total得到的直接余数也是负数，要转化为正数之后才能用。

