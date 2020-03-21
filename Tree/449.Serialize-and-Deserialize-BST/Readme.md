### 449.Serialize-and-Deserialize-BST

此题是297.Serialize and Deserialize Binary Tree的扩展。对于任意的二叉树，仅根据一种遍历无法还原这课树，一般需要两种遍历序列，或者是level order加上NULL节点的信息。

但对于BST，它有一个非常好的性质，就是仅用其先序遍历就可逆！

一种直观的想法就是，根据“先序遍历的首元素是根节点”，通过逐个大小比较，将之后的元素分为左子树和右子树两部分，分别递归构建左子树和右子树。这种方法会对同一个元素多次进行比较，需要o(n^2)的时间，太慢。（参考255.Verify Preorder Sequence in Binary Search Tree）

比较巧妙的DFS解法，是根据首元素（根节点）来更新之后左右子树的上下限。构造DFS函数
```
    TreeNode* DFS2(vector<int>& preorder,int curIdx, int MIN, int MAX)
    {
        if (curIdx>=preorder.size()) return NULL;
        
        if (preorder[curIdx]<MIN || preorder[curIdx]>MAX)
            return DFS2(preorder, curIdx+1, MIN, MAX);
        
        TreeNode* root = new TreeNode(preorder[curIdx]);
        root->left = DFS2(preorder,curIdx+1,MIN,root->val);
        root->right = DFS2(preorder,curIdx+1,root->val,MAX); 
        
        return root;
    }
```
每次DFS都推进一位（curIdx）。如果preorder[curIdx]不合当前上下限的，就不理会，继续往后面的元素找；如果符合当前上下限，那么说明preorder[curIdx]本身就适合当一个根节点，其左右子树必定在之后的元素里，于是推进一位递归调用DFS，只要合理更新上下限即可。



[Leetcode Link](https://leetcode.com/problems/serialize-and-deserialize-bst)