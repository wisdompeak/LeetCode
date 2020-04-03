### 813.Largest-Sum-of-Averages

本题求“最大值”，一般可以朝DP的方向考虑。另外，题意里有明确的分成k个subarray的要求，大概率就是第I类区间型DP。

这类DP的套路就是定义dp[i][k]，表示将前i个元素分成k个subarray的最优解，这里表示the maximzied sum of the average of each subarray. 突破口就是针对最后一个元素A[i]，它必定是在当前的最后一个subarray，考虑这个区间的首元素j会在哪里？如果选定了这个位置j，那么dp[i][k]就分解为了两个子问题，一个是dp[j-1][k-1]，是以前已经解决的状态，另一个就是s[j:k]这段区间的平均值。两者相加就是dp[i][k].我们搜索所有的j的位置，选择使dp[i][k]最大化的结果。

大致的状态转移方程如下:
```cpp
for (i=1; i<=N; i++)
  for (k=1; k<=min(i,K); k++)
  {
      // find the best break point j
      for (int j=i; j>=k; j--)
        dp[i][k] = max(dp[i][k], dp[j-1][k-1] + sum[j:i] );
  }
```
对于第I类区间型DP，最常需要关注的边界值就是dp[i][0].通常这种边界条件是非法的（就像除数不能为零一样），为了避免涉及这个量，我们把dp[i][0]都设计成最差的结果从而避免被使用，在这里就是INT_MIN. 

另外边界条件dp[0][0]通常都会是零。

[Leetcode Link](https://leetcode.com/problems/largest-sum-of-averages)
