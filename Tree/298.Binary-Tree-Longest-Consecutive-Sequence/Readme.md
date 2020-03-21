### 298.Binary-Tree-Longest-Consecutive Sequence

这是一道基本的用DFS递归的二叉树题。需要注意的细节是，对于左右子树的递归调用，需要在判断 root->val+1==root->left->val之前。

对于这样的调用是错误的：
```cpp
if (root->left!=NULL && root->val+1==root->left->val)
{
    res = max(res, DFS(root->left)+1);
}
```
因为这样的话，当左节点不是根节点的增1时，左节点将永远不会被调用DFS，这样的话，左子树可能有的最长增序列将不会被搜索到。
```cpp
if (root->left!=NULL)
{
    int temp = DFS(root->left);
    if (root->val+1==root->left->val)
      res = max(res, temp+1);
    
}
```


[Leetcode Link](https://leetcode.com/problems/binary-tree-longest-consecutive-sequence)