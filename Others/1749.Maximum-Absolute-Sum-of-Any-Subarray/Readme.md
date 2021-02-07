### 1749.Maximum-Absolute-Sum-of-Any-Subarray

#### 解法1
最大的subarray sum的绝对值，肯定来自两个种可能：最大的正的subarray sum，或者最小的负的subarray sum，所以我们把这两个问题都解出来，取绝对值较大的那个就可以了。

求max subarray sum是一个经典问题。我们令dp[i]表示截止到nums[i]的subarray的最大和（必须包括nums[i]本身），那么有```dp[i]=max(dp[i-1],nums[i])```. 全局的最优解就是所有dp[i]中的最大值。min subarray sum同理可得。

#### 解法2
任何一个```abs(sum[i:j])```都可以写成两个前缀和之差```abs(prefix[j]-prefix[i-1])```的形式。显然最优解[i:j]就是对应全局最大前缀和prefix[j]、最小前缀和prefix[i-1]。特别注意，0也是前缀和。
