### 110.Balanced-Binary-Tree

将判断isBalanced(root)转为考察depth(root). 递归的过程中一旦发现depth(node->left)和depth(node->right)不合条件、或其中任何一个已经为-1，则depth(node)就直接返回-1。
```cpp
    int depth(TreeNode* node)
    {
        if (node==NULL) return 0;
        
        int d1=depth(node->left);
        int d2=depth(node->right);
        if (d1==-1 || d2==-1 || abs(d1-d2)>1) 
            return -1;
        else
            return max(d1,d2)+1;
    }
```    
这样当depth(node)为正数时，就保证了该节点已经balanced。
```cpp
    bool isBalanced(TreeNode* root) 
    {
        if (depth(root)==-1)
            return false;
        else
            return true;
    }
```    



[Leetcode Link](https://leetcode.com/problems/balanced-binary-tree)