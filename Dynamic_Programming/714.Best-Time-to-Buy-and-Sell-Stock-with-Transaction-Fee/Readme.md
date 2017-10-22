### 714.Best-Time-to-Buy-and-Sell-Stock-with-Transaction-Fee

设置两个变量，s0表示此时没有存货的利润，s1表示此时有存货的利润。

遍历prices的所有元素，递推公式如下：
```cpp
s0 = max(s0, s1+prices[i]-fee)  // s0保持不变，或者将s1的存货卖掉
s1 = max(s1, s0-prices[i])    // s1保持不变，或者将s0购入当前的股票
```

注意，以上递推公式中需要用临时变量将s0的值储存下来，在s0改变之后可以用来update s1.
