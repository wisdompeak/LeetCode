### 105.Construct-Binary-Tree-from-Preorder-and-Inorder-Traversal

首先明确概念，先序遍历（perorder）是指第一个访问根节点；中序遍历（inorder）是指第二个访问根节点（第一个先访问左子树）。不要混淆了。

本题是经典的二叉树操作。考虑到preorder的第一个元素必定是root；所以在inorder中找到对应root的位置后，其左边就是左子树的所有节点的中序遍历，右边就是右子树的所有节点的中序遍历。

那么如何在preorder序列里面区别出哪些是左子树的节点，哪些是右子树的节点呢？通过inorder序列里左子树节点的数目！假设inorder序列里左子树节点的数目为N，那么在preorder序列里，root之后的N个元素就是左子树的先序遍历，剩下的元素就是右子树的先序遍历。

注意，需要提前根据inorder建立Hash表，这样从preorder里确定root后，就可以立即查找到其在inorder里的位置。

举个例子，DFS(vector<int>& preorder, int a, int b, vector<int>& inorder, int m, int n)，那么根节点在先序遍历中就一定是 preorder[a]，那么在中序遍历中的位置就一定是 pos = Map[preorder[a]]。所以inorder序列里, m到pos-1是左子树，pos+1到n是右子树。可知左子树的数目是N = pos-m。在preorder序列里，左子树从a+1开始，到a+N为止；显然，右子树从a+N+1开始，到b为止。


[Leetcode Link](https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal)