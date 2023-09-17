### 2858.Minimum-Edge-Reversals-So-Every-Node-Is-Reachable

典型的移根技巧。

先用一遍DFS，以node 0为根遍历全树，计算node的reversal edge的数目count.

然后第二遍DFS，从node 0开始。当dfs从节点i转移至邻接的节点j时，以节点i为根的树的reversal edge count，与节点j为根的树的reversal edge count，其实只相差了"i->j"这条边而已。如果这条边对于i而言是顺边，那么对于j而言就是逆边。反之亦然。所以他们之间的结果只是相差+1/-1而已。
