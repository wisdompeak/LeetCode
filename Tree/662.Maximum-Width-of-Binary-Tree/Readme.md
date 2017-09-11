### 662.Maximum-Width-of-Binary-Tree

利用二叉树的这个性质：若一个节点的深度是level，在该层的序号是order，则其左子树的深度是level+1且在该层的序号是order\*2-1，其右子树的深度是level+1且在该层的序号是order\*2。这样通过DFS遍历所有的节点，在Map里保存每个level都记录过哪些order，取最大最小值之差就行。

注意这里的order从1开始标记更方便。因为unordered_map<int,pair<int,int>>Map里的value值默认为0，需要靠这个零值来标记该层是否有被记录过。
