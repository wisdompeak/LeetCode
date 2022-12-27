### 879.Profitable-Schemes

我们很容易设计状态变量dp[i][person][profit]来表示在前i个项目中，恰好用person个人力、并恰好达到profit的利润的方案数。

常规的状态转移方程会长得像这样：考虑第i个项目（人力是x，利润是y）是否实施两种情况
```cpp
dp[i][person][profit] = dp[i-1][person][profit] + dp[i-1][person-x][profit-y]
```

但是这里有个问题。dp的第三个维度需要遍历的范围太大，达到100*100=1e4，那么整个dp的空间就太大了。我们容易发现，第三个维度其实只要开到minProfit就可以了，对于`profit = minProfit, minProfit+1, minProfit+2 ... `我们不关心它们各自的dp值，我们只在乎他们的总和。所以我们可以将这些dp值都累加存放在dp[i][person][minProfit]里。

但是这里就又出现了一个问题，当你profit遍历到minProfit时，上述的状态转移方程就不成立了。因为minProfit其实不代表了利润恰好是它，而是代表了所有大于等于它的利润。此时你再从`dp[i-1][person-x][profit-y]`转移而来就没有道理。所以我们不能用这种传统的状态转移方法。

传统的状态转移方法：根据以往的dp求dp[i]。逆向的状态转移方法：根据当前已知的dp[i]，推出对今后dp值的影响。

在本题中，我们假设已知`dp[i][person][profit]`，那么我们可以推测对i+1的影响：
```cpp
dp[i+1][j][p] += dp[i][j][p];
dp[i+1][j+group[i+1]][min(minProfit, p+profit[i+1])] += dp[i][j][p];
```

最终答案就是sum{dp[m][j][minProfit]}，其中j=0,1,2...,n

[Leetcode Link](https://leetcode.com/problems/profitable-schemes)
