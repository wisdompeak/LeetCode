### 714.Best-Time-to-Buy-and-Sell-Stock-with-Transaction-Fee

设置两个变量，sold表示此时没有存货的利润，hold表示此时有存货的利润。

遍历prices的所有元素，递推公式如下：
```cpp
sold = max(sold_tmp, hold_tmp+prices[i]-fee)  // sold的两种选择：保持原先的sold保持不变，或者将原先hold的存货卖掉
hold = max(hold_tmp, sold_tmp-prices[i])      // hold的两种选择：保持原先的hold保持不变，或者在原先sold状态下购入当前的股票
```

注意，初始状态是：
1. ```sold = 0```手头没有股票自然利润是0.
2. ```hold = -math.inf```初始状态下怎么可能hold任何股票呢？解决的技巧是将hold设置为最小值，那么下一步无论更新sold还是hold，都不会考虑之前的hold_tmp状态。

类似的题目还有：376.Wiggle-Subsequence，487.Max-Consecutive-Ones-II


[Leetcode Link](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee)