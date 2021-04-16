### 1799.Maximize-Score-After-N-Operations

观察数据大小，容易判定就是一个状态压缩的动态规划问题。转移方程是：
```
for i=1:n
 dp[集合大小是2i的state] = dp[集合大小是2(i-1)的substate] + gcd(x,y)
```
其中substate必须是state的子集，另外x和y就是差集state-substate里的那两个元素。

于是本题的关键就是如何高效遍历状态。这里就显现了Gosper's Hack的威力，它可以直接遍历所有大小为m bit、其中含有k个1 bit的二进制状态。假设2n=14，故外层的循环就是2^14/2=8192次。对于内层循环，有两种遍历策略：
1. 遍历所有state的子集，再过滤是否substate的集合大小是2(i-1)
2. 遍历所有集合大小是2(i-1)的substate，再过滤是否是state的子集。
 
对于策略2，考虑最复杂的情况，遍历有6个1的substate，总共有C(14,6) = 3003种状态，两层循环组合起来的时间复杂度应该也就是1e6数量级，可以接受。
