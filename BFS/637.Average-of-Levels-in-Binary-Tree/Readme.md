### 637.Average-of-Levels-in-Binary-Tree

BFS所用的队列不必用pair来携带level信息。在遍历完一层之后，就能用一个for循环来指定遍历下一个层级节点的数目。

另一个好处是，这样在队列的构造过程中就可以进行平均数的计算，不必等到整棵树遍历完之后再做计算。


[Leetcode Link](https://leetcode.com/problems/average-of-levels-in-binary-tree)