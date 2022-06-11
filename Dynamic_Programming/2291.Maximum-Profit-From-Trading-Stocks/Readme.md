### 2291.Maximum-Profit-From-Trading-Stocks

非常直观的01背包问题。挨个遍历物品。考察对于给定某budget情况下，加入这个物品是否能带来更大的收益，即```dp[budget] = max(dp[budget], dp[budget-cost[i]] + profit[i])```
