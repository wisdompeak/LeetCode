### 156.Binary-Tree-Upside-Down

此题的意思是：对于一个根-左-右的基本树状结构，右子树保证只有一个或为空。要求变形后，以左子树为根，把原来的根和右节点作为新根节点的右、左节点。

试想一下，原先的左节点的两个后继节点是朝下分叉的，要变成朝右上分叉，怎么整？那就为左节点制作一份拷贝。新拷贝rootAlien与原先的root数据相同，但是后继节点的朝向是右上方。DFS函数一路沿着左节点递归调用，每走一步，就扩展这样的新拷贝。
```cpp
    TreeNode* DFS(TreeNode* root, TreeNode* rootAlien)
    {
        if (root->left==NULL) 
            return rootAlien;
        else
        {
            TreeNode* nextRoot = root->left;    //左节点要变成新的根节点
            TreeNode* nextRootAlien = new TreeNode(root->left->val); //为新的根节点制作一份拷贝
            nextRootAlien->right = rootAlien;  //设置新拷贝的后继节点。注意，新拷贝的右子树就是之前的rootAlien
            nextRootAlien->left = root->right; // 新拷贝的右子树就是原始root的右节点
            return DFS(nextRoot,nextRootAlien); // 递归调用，作用于左节点和左节点的新拷贝
        }        
    }
```    
