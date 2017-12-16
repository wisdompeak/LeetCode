### 742.Closest-Leaf-in-a-Binary-Tree

一般解决关于二叉树的问题，90%都可以用DFS解决。此题也不例外，但需要仔细考虑设计。

首先要明确，一条从节点k到最近叶子节点的路径，除了本身直接往下走之外，都需要经过一个拐点，所以拐点和路径就是一一对应的关系。我们的目的就是考察所有的节点，找出以其为拐点的路径的最短长度，

对于节点node，我们首先要知道node到节点k之间的距离，这需要一个递归函数 DFS_find_k。如果节点k在node的左子树，那么我们就要考虑沿着node的右子树往下、到达叶子节点的最短路径，这有需要一个递归函数 DFS_find_closest_leaf. 于是 DFS_find_k(node->left)+2+DFS_find_k(node->right) 就是整条路径的长度。反之，如果节点k在node的右子树，那么 DFS_find_k(node->right)+2+DFS_find_k(node->left) 就是整条路径的长度。注意，两个长度只可能有一个有效。

从上可知，我们提前做两次整棵树的搜索，记录下所有节点对应的 Dist_to_k[node] 和 Dist_to_Leaf[node]，那么就可以得到所有的路径长度，找出最短的那条。

另外，注意我们在DFS_find_closest_leaf的过程中，顺带把ClosetLeaf[node]也记录下来，因为结果需要输出的是这个叶子节点的val。
