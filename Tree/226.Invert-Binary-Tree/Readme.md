### 226.Invert-Binary-Tree

本题有两种做法。常规的递归想法是：
```
root->left=invert(root->right);
root->right=invert(root->left);
```
但注意上述的写法是有问题的，因为第一行里已经把root->left改变了，所以第二行就不成立了。所以应该用temp把invert(root->right)存起来，之后再传给root->left.

另外一种就很巧妙：
```
swap(root->left,root->right);
root->left=invert(root->left);
root->right=invert(root->right);
```
注意代码第一行，作用是把整个根节点的左右子树都整体对换了。


[Leetcode Link](https://leetcode.com/problems/invert-binary-tree)