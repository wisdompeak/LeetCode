### 123.Best-Time-to-Buy-and-Sell-Stock-III

此题属于DP的范畴,但是不需要存储庞大的状态数组.本题中,每一天的决策,仅仅取决于之前一天的若干个状态.

一天之内的状态,只有四种:已经买了一只股buy1,已经卖了一只股sold1,已经买了第二只股buy2,已经卖了第二只股sold2.那么显然每一天的状态更新是:
```cpp
buy1 = max(buy1,-p)
sold1 = max(sold1, buy1+p)
buy2 = max(buy2,sold1-p)
sold2 = max(sold2, buy2+p)
```
注意等号右边的变量都是前一天的状态. 另外需要考虑初始状态:buy1=-inf, sold1=0, buy2=-inf, sold2=0

跟这一题类似的题目有:376,487,714,552


[Leetcode Link](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii)