### 3654.Minimum-Sum-After-Divisible-Sum-Deletions

首先，题意中“after each deletion, the remaining elements close the gap”这个表述其实带有迷惑性。我们其实不需要这样的操作。假设有a,b,c,d四个位置，我们先删除[b,c]，剩余合并之后再删除[a,d]，那么必然等价于可以直接删除[a,d]。因为[b:c]能被k整除，且[a:b)+(c:d]能被k整除，则[a:d]一定也能被k整除。因此原题可以转化为，在nums里删除若干段互不相交的、能被k整除的区间，使得剩余的元素之和最小。

由此本题就具有了典型的“无后效性”。我们可以考虑动态规划。令dp[i]表示只处理前i个元素能够得到最优解，突破口就在于nums[i]的处理。
1. 如果不删除nums[i]，那么直接有`dp[i] = dp[i-1]+nums[i]`。
2. 如果删除nums[i]，那么我们需要找到一个位置j，使得sum[j+1:i]能被k整除，则有转移方程`dp[i]=dp[j]`。满足条件“sum[j+1:i]能被k整除”的j可能有多处，它们明显有一个共同的特征，就是前缀和presum[j]必须与presum[i]关于k同余。于是我们可以将i之前的所有dp值按照`presum[j]%k`的余数分类，每种余数只记录最小的dp值，记作dp_by_r。假设`presum[i]%k==r`，那么我们就可以直接得到`dp_by_r[r]`，就是dp[i]的前驱状态。

最终返回dp[n]即可。
