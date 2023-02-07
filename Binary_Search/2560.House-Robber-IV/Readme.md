### 2560.House-Robber-IV

这道题的题意需要仔细理解。最小化capability意味着我们需要尽量挑数值小的house，但是如果我们挑的数值都太小的话，就没有足够的house来满足“at least k houses”的约束。于是我们就发现了单调性的变化：capability越小，那么可选的house就越少。capability越大，那么可选的house就越多。于是我们需要找恰好的capability，使得可选的house恰好大于等于k。因此，这是一个二分搜值的算法。

我们猜测需要的capability是c，那么可以选多少house呢？满足两个条件：挑选的house的数值不能大于c，挑选的house不能相邻。对于后者，我们知道house robber的一个通用技巧，就是对每一个house都讨论取还是不取两种策略。所以我们令`dp[i][0]`表示第i个house不抢的策略下所能选中的house数目，`dp[i][1]`表示第i个house抢的策略下所能选中的house数目。

考虑第i个房子，如果`house[i]>c`，我们终归是不能抢的，故第i-1个house抢不抢无所谓。
```cpp
dp[i][0] = max(dp[i-1][0], dp[i-1][1]);
dp[i][1] = INT_MIN/2;
```
考虑第i个房子，如果`house[i]<=c`，我们可以选择抢，也可以选择不抢
```cpp
dp[i][0] = max(dp[i-1][0], dp[i-1][1]);
dp[i][1] = dp[i-1][0];
```
由此将所有的dp[i][x]都更新。最后考察dp[n-1][x]能否大于k，即意味着在当前c的设置下，能否实现至少抢k个房子。
