### 1770.Maximum-Score-from-Performing-Multiplication-Operations

这道题是比较新颖的区间型DP。我们常见的区间型DP的定义是dp[i][j]表示在区间[i:j]内可以得到的最优解。但是本题中这样定义的话需要开辟N^2的空间，会MLE。我们发现本题中需要拿取的数字个数只有m个，远比nums的长度要小，所以我们转换思路，将dp[i][j]表示我们在左侧拿了i个、右侧拿了j个可以得到的最优解。虽然有两个区间，但我们同样只需要用两个下标可以表示了。

dp[i][j]的最优解取决于最后一步拿的第i+j个数字是在左边还是右边。所以状态转移方程是：
```cpp
dp[i][j] = max(dp[i-1][j]+nums[i]*multipliers[i+j], dp[i][j-1]+nums[n-j+1]*multipliers[i+j]);  
```
dp的边界条件是dp[0][0] = 0. 
