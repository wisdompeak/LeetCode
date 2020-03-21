### 106.Construct-Binary-Tree-from-Inorder-and-Postorder-Traversal

本题和 105. Construct Binary Tree from Preorder and Inorder Traversal 一样的思路。根据后续遍历的性质，postorder数组的最后一个元素就是根节点。在inorder数组里面通过之前构建的hash映射找到这个根节点，就可以将整个inorder数组分成左右两部分，分别构造左子树和右子树。

postorder数组的拆分方法：根据inorder数组拆分得到的左右子树的元素数目，来确定postorder序列里前面多少个元素属于左子树。


[Leetcode Link](https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal)