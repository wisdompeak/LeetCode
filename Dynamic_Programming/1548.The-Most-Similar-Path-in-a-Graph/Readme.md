### 1548.The-Most-Similar-Path-in-a-Graph

令dp[t][i]表示路径的第t个位置设置为第i个城市，所能得到的最小edit distance。显然，它的前驱状态就是dp[t-1][j]，其中j和i之间有通路。因此
```
dp[t][i] = min{dp[t-1][j] + (city[i]!=targetPath[t])} for all j->i
```
