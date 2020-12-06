### 1676.Lowest-Common-Ancestor-of-a-Binary-Tree-IV

一个比较简单的算法思想就是，深度搜索每个节点node，查看它的子节点（包括自身）有多少个节点是在集合nodes里面的。如果数目和nodes的集合大小相同，那么node就是集合里所有节点的ancestor。

注意，只有在DFS过程中第一个被检测到的这样的节点才是答案。更高层的节点，虽然也满足判定条件，但并不是lowest common ancestor.
