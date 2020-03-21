### 834.Sum-of-Distances-in-Tree

首先回顾一下关于图论的几个概念。树是图的一种，是指没有回路的连通图。对于这种图，任意一个节点都可以当做root从而展开为一棵直观意义上的树。

本题也是如此，我们可以任意选取一个节点定义为root，然后可以用BFS建立起一个Hash表来代表传统意义上树结构里parent->child的连接关系（注意，因为是树，反向的关系我们不记录在Hash表里）。

然后我们可以做什么呢？比较容易用递归办到的，就是root到所有子节点的距离之和，标记为f(root)。那么接下来，如何得到一个子节点child到其他所有节点的距离之和呢？难道要以该节点为根重新展开一张树吗？其实我们可以考虑f(parent)和f(child)之间的关系。

假设已知f(parent)，如果我们把起点从parent迁到child的话，那么到所有除child子树之外的节点，距离都增加了1；到所有child子树的节点，距离都减少了1.

所以有如下的关系
```
f(child) = f(parent)+(除child子树之外所有节点的数目)-(child子树的节点数目)
```
可见，所有的f都可以自上而下通过递归得到。


[Leetcode Link](https://leetcode.com/problems/sum-of-distances-in-tree)