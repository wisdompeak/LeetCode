### 624.Maximum-Distance-in-Arrays

最粗浅的最优策略就是，把每个数组的第一个元素挑出来组成Mins数组，每个数组的最后一个元素挑出来组成Maxs数组。理想情况下，Maxs.back()-Mins[0]就是最大的一对差值。

当Maxs.back()和Mins[0]来自同一个数组怎么办？这时候考察Maxs[n-2]-Mins[0]以及Maxs.back()-Mins[1]，取其中较小的。而且这两对数字肯定不会是在同一个数组中的。


[Leetcode Link](https://leetcode.com/problems/maximum-distance-in-arrays)