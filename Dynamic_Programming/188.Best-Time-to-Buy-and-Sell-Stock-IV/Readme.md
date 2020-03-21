### 188.Best-Time-to-Buy-and-Sell-Stock-IV

此题是对之前股票系列I，II，III的综合考察，并推广到任意k次交易的条件。

基本思路还是从第i天的策略考虑起。第i天如果卖出的话，说明第i-1天必须手头有股票；如果是买入的话，说明第i-1天必须手头没有股票。因此我们可以粗略地写下：```dp[i] = max{dp[i-1][yes]+sell, dp[i-1][no]+buy}```这就提示我们dp其实有两个维度，dp[i][yes/no]，第二个维度代表了持有或不持有股票。这时候我们可以写出状态转移方程：
```
for (int i=0; i<n; i++)
{
    dp[i][yes] = max( dp[i-1][no]+buy, dp[i-1][yes]+hold );
    dp[i][no] =  max( dp[i-1][yes]+sell, dp[i-1][no]+hold );
}
return dp[n-1][no];
```
但是这个状态转移方程并没有考虑到对于交易次数的约束。我们因此修改状态变量为dp[i][yes/no][j]，其中j表示经历过j次的股票买入。显然，第i天买入第j只股票，需要要求第i-1天已经卖出第j-1只股票；第i天卖出第j只股票，需要要求第i-1天已经入手第j只股票。因此类推，就可以把j写入状态转移方程中。
```
for (int i=0; i<n; i++)
{
    for (int j=0; j<=k; j++)
    {
      dp[i][yes][j] = max { dp[i-1][no][j-1]+buy, dp[i-1][yes][j]+hold };
      dp[i][no][j] = max {dp[i-1][yes][j]+sell, dp[i-1][no][j]+hold  };
    }
}
return dp[n-1][no];
```
进一步，yes/no的状态维度可以拆分为两个dp变量：
```
  hold[i][j] = max { sold[i-1][j-1]+buy, hold[i-1][j] }
  sold[i][j] = max { hold[i-1][j]+sell, sold[i-1][j] }
```
至此，写出最多k次交易的最大利润已经不难，返回的结果是sold[n-1][j]中的最大值。

本题最有意思的一点是，k可以很大，远大于prices的天数。这样的话，题目就等效于无限次的操作，这样就可以用 122. Best Time to Buy and Sell Stock II
里面的技巧来解，时间复杂度反而从o(n*k)降到了o(n).


[Leetcode Link](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv)