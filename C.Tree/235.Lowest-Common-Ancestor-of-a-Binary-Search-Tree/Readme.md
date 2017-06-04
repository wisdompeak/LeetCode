### 235.Lowest-Common-Ancestor-of-a-Binary-Search-Tree

从根节点开始考察，如果p,q都比root小，则root移动至其左子树；否则，root移动至其右子树。直到发现p,q在root节点的两侧，则root是最低共同节点。

### 236.Lowest Common Ancestor of a Binary Tree

和235不同，没有任何线索提示这两个节点的位置关系。所以只好用DFS搜索出抵达这两个节点的路径。通过路径的比较，找出共同的一段path，即可得出最低的公共节点。

DFS函数会一路向下层搜索直到发现节点p，然后在返回的过程中将路径所经过的所有节点存在数组P中。
```cpp
    bool DFS(TreeNode* node, TreeNode* p, vector<TreeNode*>&P)
    {
        if (node==NULL)
            return false;        
        
        if (node==p || DFS(node->left, p, P) || DFS(node->right, p, P))
        {
            P.push_back(node);
            return true;
        }
        else
            return false;
        
    }
```    
得到数组P和Q之后，只要从后往前比较两个数组，追踪它们相同的路径截止到哪一位为止就行了。
