### 742.Closest-Leaf-in-a-Binary-Tree

一般解决关于二叉树的问题，90%都可以用DFS解决。此题也不例外，但需要仔细考虑设计。

首先要明确，从节点k到最近叶子节点的路径，有两种可能：第一种只有一种情况，即从k节点本身开始直接往下走之外；第二种就是可能先向上走，然后经过一个拐点，再从另一端的子树往下。所以这个“拐点”就和路径就是一一对应的关系。我们的目的就是考察所有的节点，找出以其为拐点、“从节点k到最近叶子节点”的路径的最短长度，

对于节点node，我们首先要知道node到节点k之间的距离，这需要一个递归函数 DFS_find_k。如果节点k在node的左子树，那么我们就要考虑沿着node的右子树往下、到达叶子节点的最短路径，这又需要一个递归函数 DFS_find_closest_leaf. 于是 DFS_find_k(node->left)+2+DFS_find_closest_leaf(node->right) 就是整条路径的长度。反之，如果节点k在node的右子树，那么 DFS_find_closest_leaf(node->right)+2+DFS_find_k(node->left) 就是整条路径的长度。注意，两个长度只可能有一个有效。

从上可知，我们可以提前做一次整棵树的DFS_find_closest_leaf搜索，记录下所有节点对应的 Dist_to_Leaf[node]，顺带把ClosetLeaf[node]也记录下来，因为结果需要输出的是这个叶子节点的val。然后再过一遍DFS_find_k，对于经过的每一个节点，我们都可以算出如上所述的路径长度。然后再在全局变量中取最小。

注意：慎用INT_MAX，因为在你不知情的情况下很可能会对INT_MAX做了运算，而INT_MAX+1反而成了最小值。


[Leetcode Link](https://leetcode.com/problems/closest-leaf-in-a-binary-tree)