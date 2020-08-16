### 1548.The-Most-Similar-Path-in-a-Graph

令dp[t][i]表示路径的第t个位置设置为第i个城市，所能得到的最小edit distance。显然，它的前驱状态就是dp[t-1][j]，其中j和i之间有通路。因此
```
dp[t][i] = min{dp[t-1][j] + (city[i]!=targetPath[t])} for all j->i
```
答案就是选择dp[T-1][?]中最小值。

本题还需要打印出路径，因此需要额外记录prev[t][i]表示dp[t][i]的前驱状态对应的城市编号。然后从dp[T-1][?]最小值所对应的那个城市作为终点，根据Prev的信息往前倒推出整条path。
