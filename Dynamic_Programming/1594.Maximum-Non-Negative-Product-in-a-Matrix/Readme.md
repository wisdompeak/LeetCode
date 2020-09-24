### 1594.Maximum-Non-Negative-Product-in-a-Matrix

本题的思想与 152.Maximum-Product-Subarray 相同。

和传统的最优路径题一样，令dp[i][j]表示从左上角走到(i,j)的最优代价（即路径乘积最大）。根据规则，dp[i][j]仅由dp[i-1][j]和dp[i][j-1]转移而来。但是不同于以往的套路：
```cpp
dp[i][j] = max(dp[i][j-1]*nums[i][j], dp[i-1][j]*nums[i][j])
```
在这里，如果nums[i][j]为负数的话，我们希望已知的反而是走到(i-1,j)和(i,j-1)的最小乘积路径，这样与nums[i][j]相乘之后才能得到的是最大乘积路径。这就提醒我们要维护两个状态变量，dp1[i][j]和dp2[i][j]来分别记录到当前的最大乘积路径和最小乘积路径。
```cpp
dp1[i][j] = max(max(dp1[i][j-1]*nums[i][j], dp1[i-1][j]*nums[i][j]), max(dp2[i][j-1]*nums[i][j], dp2[i-1][j]*nums[i][j]));
dp2[i][j] = min(min(dp1[i][j-1]*nums[i][j], dp1[i-1][j]*nums[i][j]), min(dp2[i][j-1]*nums[i][j], dp2[i-1][j]*nums[i][j]))'
```
