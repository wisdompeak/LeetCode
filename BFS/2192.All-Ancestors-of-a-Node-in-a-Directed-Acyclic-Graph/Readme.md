### 2192.All-Ancestors-of-a-Node-in-a-Directed-Acyclic-Graph

本题就是常规的拓扑排序，依然是剥洋葱的思想，每个回合将当前入度减为零的节点放入队列中，持续BFS。

本题可以暴力一些，直接给每一个节点配一个集合ancestor来记录它的祖先。在将节点i弹出队列的时候，查看i的所有后续节点j，将ancestor[i]的元素和i本身都加入ancestor[j]中。
