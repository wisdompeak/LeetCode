### 3553.Minimum-Weighted-Subgraph-With-the-Required-Paths-II

本题的第一个知识点是：在一棵树里，联通u,v,w三个节点的最小子树的权重和，就是`[dist(u,v)+dist(u,w)+dist(v,w)]/2`.

本体的第二个知识点是：在一棵树里，联通x,y两点的路径长度，等于`dist(r,x)+dist(r,y)-2*dist(r,c)`，其中r是整棵树的根节点，c是x和y的LCA（lowest common ancester）。

任意一点到距离根节点的距离dist(r,x)可以通过DFS得到。于是本题的关键点就是求任意两点的LCA，于是就是一个binary list经典题。

我们需要处理得到一个数组up[v][k]，表示节点v往上（朝根节点方向）走2^k步能够得到的位置。转移方程就是`up[v][k] = up[up[v][k-1]][k-1]`. 边界条件就是对于一对父子节点a->b，有`up[b][0]=a`.
