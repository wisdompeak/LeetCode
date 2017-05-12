### 437.Path-Sum-III

此题是112,113的follow up。不要path一定是从root到leaf。

在这种情况下，每个节点都有可能是path的起点。所以需要遍历树的所有节点，对每个节点都寻找pathSum(node,sum)。

另外，(root->val==sum)并不意味着path的终点，如果子树还有和为零的路径，也合题意。所以遇到这种情况，还要进一步加上左右子树路径和为0的子问题。
```cpp
    int pathSumNum(TreeNode* node, int sum)
    {
        if (node==NULL) return 0;
        if (node->val==sum) return 1+pathSumNum(node->left,0)+pathSumNum(node->right,0);
        return pathSumNum(node->left,sum-node->val)+pathSumNum(node->right,sum-node->val);
    }
```    
