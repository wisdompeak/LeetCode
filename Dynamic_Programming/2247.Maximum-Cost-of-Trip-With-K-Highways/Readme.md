### 2247.Maximum-Cost-of-Trip-With-K-Highways

本题是说要找出一条最长的路径，恰能包含k+1个节点（起始点可以自由选择）。要求节点不能重复经过（自然边也不会重复经过）。

这是一个经典的旅行商问题（TSP）。解法和```943.Find-the-Shortest-Superstring```一样。考虑到节点总数不超过15个，我们可以用二进制数state表示经过的节点的集合。令dp[state][last]表示走过了state所代表的节点集合、并且最后一站是节点last的情况下，所能得到的最优解。假设last与j相邻，且j不在state中，则有状态转移方程
```cpp
dp[state + (1<<j)][j] = dp[state][last] + cost[last][j]
```
最终考察所有含有k+1个节点的state，取其dp值的最大。
