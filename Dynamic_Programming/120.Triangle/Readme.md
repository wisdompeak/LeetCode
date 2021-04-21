### 120.Triangle

最基本的DP题。令dp[i][j]表示从起点到第i行第j列所经过的最短权重和，那么
```cpp
dp[i][j] = min(dp[i-1][j], dp[i-1][j-1]) + triangle[i][j]
```
注意当j==0和j==i时需要单独处理。
