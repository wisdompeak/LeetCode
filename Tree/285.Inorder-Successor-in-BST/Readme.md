### 285.Inorder-Successor-in-BST

很明显，基本思想就是对二叉树进行中序遍历，遍历到p后，输出它的下一个遍历对象。

因此，需要设置一个全局变量 TreeNode\* last 来存储最近读到的节点。在遍历的过程中，如果发现last==p，则当前读取的节点就是想要的东西；否则更新last为当前读取的节点。

我们首选比较清晰的递归法来遍历。注意，根据题目要求，这次我们需要给DFS设置一个返回值。初步的框架如下：
```cpp
    bool DFS(TreeNode* root, TreeNode* p)
    {
        if (root==NULL) return false;        
        
        if (DFS(root->left,p)) return true;   // 任务已经完成
        
        if (last==p) 
        {
            result=root;
            return true;    // 任务完成
        }
        else
            last=root;        
        
        if (DFS(root->right,p)) return true;
        
        return false;   // 任务未完成
    }
```


[Leetcode Link](https://leetcode.com/problems/inorder-successor-in-bst)