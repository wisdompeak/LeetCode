### 309.Best-Time-to-Buy-and-Sell-Stock-with-Cooldown

此题和该系列的其他题目一样，用几个状态变量来做DP。此题比较特殊的情况是，仅有hold和sold两个状态是不够的。我们考虑hold表示手头有股票时候的收益，sold表示手头已经卖出了股票的收益，题目可知我们试图更新sold的时候不能用hold+price[i]，所以我们还需要sold_cd表示手头的股票已经出手了一天以上。

我们不难分析出这三个状态的转移方程是：
```
hold = max(hold, sold_cd-prices[i])
sold = max(sold, hold+prices[i])
sold_cd = sold
```
注意所有等号右边的状态变量应该是上一轮的，所以会需要在更新前先缓存一下。


[Leetcode Link](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown)