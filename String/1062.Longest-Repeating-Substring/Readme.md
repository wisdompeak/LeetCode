### 1062.Longest-Repeating-Substring

#### 解法1： DP
此题和```1044.Longest-Duplicate-Substring```一模一样，唯一的区别是数据范围更小一些，因此可以用o(N^2)的DP算法。

我们将S分别看做S1和S2，那么此题就变成求两个字符串的longest common substring. 我们令dp[i][j]表示以S1[i]结尾、S2[j]结尾的最长的字符串的长度。则有状态转移方程：
```
if (S[i]==S[j]) dp[i][j] = dp[i-1][j-1] + 1;
```
