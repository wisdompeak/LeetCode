### 1937.Maximum-Number-of-Points-with-Cost

我们很容易写出这样的DP写法：
```cpp
for (int i=0; i<m; i++)
  for (int j=0; j<n; j++)
    for (int k=0; k<n; k++)
      dp[i][j] = max(dp[i][j], dp[i-1][k] - abs(j-k) + points[i][j]);
```
这样的时间复杂度是o(MNN)，显然会TLE。怎么改进呢？

我们将绝对值符号拆开就会发现
```cpp
dp[i][j] = max{ dp[i-1][k] + k - j  + points[i][j]};    for k<=j
dp[i][j] = max{ dp[i-1][k] - k + j  + points[i][j]};    for k>=j
```
我们将```dp[i-1][k]+k```看做是一个序列，那么dp[i][j]就需要在这个序列的前j个里面挑一个最大的。于是dp[i][j]其实就是这个序列的rolling max value，再加上一个常数项，计算量可以均摊成o(1)。

同理，我们将将```dp[i-1][k]-k```看做是一个序列，那么dp[i][j]就需要在这个序列的后面n-j个里面挑一个最大的。于是dp[i][j]也是这个序列的rolling max value再加上一个常数项，计算量可以均摊成o(1)。

注意，dp[i][j]最终是需要在两段区间（k<=j 和 k>=j）各自的最大值中挑选一个更大的。
