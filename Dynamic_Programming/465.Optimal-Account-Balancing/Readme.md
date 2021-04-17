### 465.Optimal-Account-Balancing

此题是个经典的NP-complete问题。我们知道，如果N个人的净负债为零的话，我们最多需要N-1次转账就可以实现抹平。所以我们的目的是将所有人尽量多的拆成若干个净负债为零的小组。这样，最优答案就是总人数减去小组的个数。

NP问题的搜索算法，一般有两个方向：DFS和状态压缩DP。对于本题，状态压缩DP是经典的解法。

令一个Ｎ位的二进制数state来记录哪些人被选中组成小组，sum[state]表示这群人的集体净负债，dp[state]表示这群人实现账目平衡需要的最少操作数（也就是对应最多包含了多少个零净负债小组）。对于满足```sum[state]==0```的集合，我们试图将其拆分成两个零净负债的子集，所以我们遍历其子集subset：如果sum[subset]也为零，那么dp[state]就有机会更新为两部分子集的dp之和。
```cpp
      for (int state = 0; state < (1<<n); state++)
        {
            if (sum[state] != 0)  continue;
            dp[state] = __builtin_popcount(state)-1;
            for (int subset=state-1; subset>0; subset=(subset-1)&state)
            {
                if (sum[subset]==0)
                  dp[state] = min(dp[state], dp[subset]+dp[state-subset]);
            }
        }
```
最终输出的答案就是dp[(1<<N)-1]. 上述两层for循环实现了遍历所有状态的子集，时间复杂度是o(3^N).

[Leetcode Link](https://leetcode.com/problems/optimal-account-balancing)
