### 144.Binary-Tree-Preorder-Traversal

二叉树中的经典题。用栈来实现二叉树的先序遍历（首先访问根节点）

基本思路：如果root非空，则读取数值（因为此root就是根节点）并压入栈，如果可能root=root->left一路朝左遍历到底层。如果发现root是空，则取栈顶元素并退栈（因为根节点都已经访问过了），令root是栈顶元素的右子树。然后就是重复之前的判断。


[Leetcode Link](https://leetcode.com/problems/binary-tree-preorder-traversal)