### 1269.Number-of-Ways-to-Stay-in-the-Same-Place-After-Some-Steps

本题的DP状态很容易定义：dp[k][i]就表示第k步能达到第i个位置的方案数。并且状态转移方程也很容易写出来：
```cpp
      for (int k=1; k<=steps; k++)             
            for (int i=0; i<arrLen; i++)
            {
                dp[k][i] = dp[k-1][i-1]+dp[k-1][i+1]+dp[k-1][i];
            }
        }
```
但是查看数据范围后发现，```steps*arrLen```达到了1e8数量级，这两个循环是会超时的。

本题优化的技巧在于，题目只问了steps之后到达index=0的方案数，而并没有问到达任意index=i的方案数。再看到steps只有500，于是就能得到启发：我们并不关心位置大于steps/2的那些地方的状态，它们只有在steps/2时间之后才会被更新，而反馈影响给index=0又需要多于steps/2的时间，因此它们永远不会影响到dp[steps][0].本题的极限就是前steps/2不停向右，后steps/2不停向左，所以我们只需要在第二层循环更新到steps/2即可。

事实上，对于任意steps/2之后的t步，我们甚至不用更新steps/2的最后t个位置的状态。因为那些时刻那些位置的状态，永远也不能赶在steps这个时刻影响到index=0.

[Leetcode Link](https://leetcode.com/problems/number-of-ways-to-stay-in-the-same-place-after-some-steps)
