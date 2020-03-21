### 549.Binary-Tree-Longest-Consecutive-Sequence-II

第一步：从上到下递归调用所有的节点，每个节点都算出以其为顶点的最长增序列和最长减序列，并将这两个长度存放在两个作为全局的Hash表中。

第二部：DFS遍历所有节点，遇到每个节点时，都可以算出它的longest consecutive sequence长度 IS[node]+DS[node]-1，不断更新最终结果。



[Leetcode Link](https://leetcode.com/problems/binary-tree-longest-consecutive-sequence-ii)