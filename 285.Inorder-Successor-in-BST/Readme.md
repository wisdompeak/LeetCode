### 285.Inorder-Successor-in-BST

很明显，基本思想就是对二叉树进行中序遍历，遍历到p后，输出它的下一个遍历对象。

因此，需要设置一个全局变量 TreeNode\* last 来存储最近读到的节点。在遍历的过程中，如果发现last==p，则当前读取的节点就是想要的东西；否则更新last为当前读取的节点。

我们首选比较清晰的递归法来遍历。注意，根据题目要求，这次我们需要给DFS设置一个返回值。初步的框架如下：
```cpp
    TreeNode* DFS(TreeNode* root, TreeNode* p)
    {
        if (root==NULL) return NULL;        
        DFS(root->left,p);               
        if (last==p) 
            return root;
        else
            last=root;        
        DFS(root->right,p);
    }
```
注意到 DFS(root->left,p) 和 DFS(root->right,p) 也应该是有返回值的。它们是什么呢？不难明白，如果 DFS(root->left,p)已经能够返回一个非NULL的节点，那么这个东西就已经是我们想要的结果，整个函数就可以直接返回那个节点，后续的操作都不需要了。因此，我们知道在DFS函数里，其实需要顺次查验 DFS(root->left)、root、DFS(root->right) 三个结果，遇到非NULL的话立即返回这个值；直至都没有得到理想答案的话，最后返回NULL。

