### 718.Maximum-Length-of-Repeated-Subarray

本题的本质就是Longest Common Subarray，和Longest Common Subsequence属于同一类的题目，双序列DP是最常规的解法。本题的状态转移方程更直观。

根据双序列DP的套路，令dp[i][j]表示以i结尾的subarray和以j结尾的subarray相等的最大长度，则有：
```
dp[i][j] = dp[i-1][j-1]+1 if A[i]==B[j] else 0
```
