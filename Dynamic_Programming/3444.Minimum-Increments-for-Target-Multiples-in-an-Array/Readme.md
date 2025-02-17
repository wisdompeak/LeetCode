### 3444.Minimum-Increments-for-Target-Multiples-in-an-Array

本题的一个难点就是nums里的某个元素在变换后可以是targets里一个元素的倍数，也可以是多个元素的公倍数。此时如果注意到targets里的元素个数不超过4，应该可以想到枚举其所有的子集，来与nums里的某个数对应。因此这是一个基于bit mask的DP问题。

我们令dp[i][state]表示在nums的前i个元素里，已经满足了是targets里state代表的那些元素的倍数，需要的最少操作代价。此时针对nums[i]的决策无非两种情况。
1. nums[i]并没有成为state里的任何元素的倍数，那么`dp[i][state]=dp[i-1][state]`.
2. nums[i]是state里某些元素的（公）倍数。于是我们需要枚举state里的子集subset，就有`dp[i][state]=dp[i-1][state-subset]+cost(nums[i], targets[subset]`。这里的cost，显然就是将nums[i]增加至targets[subset]所对应的最小公倍数即可。

最终答案就是dp[n][(1<<m)-1]，表示将nums的所有元素考察完之后，实现覆盖了targets里所有元素的倍数，所对应的最小代价。
