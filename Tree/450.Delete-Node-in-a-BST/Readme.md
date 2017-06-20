### 450.Delete-Node-in-a-BST

1. 寻找要被删除的节点时，不着急利用BST的性质一下子循着key找出来，想办法用递归的形式去做。
```cpp
  if (key < root->val) 
    root->left = deleteNode(root->left,key);
  else
    root->right = deleteNode(root->right,key);
```
2. 找到要被删除的节点时，考虑该节点的子节点的情况，分类讨论。
```cpp
            if (root->left==NULL && root->right==NULL)
                return NULL;
            else if (root->left==NULL)
                return root->right;
            else if (root->right==NULL)
                return root->left;    
```                
3.当待删除的root节点有左右子树时，情况相对复杂。先找到右子树里的最小值，根据BST的性质，它的数值应该就是替换root的数值。替换之后，整个树就有两个重复的节点，那么就可以对右子树做递归，目标是删除这个新key。
```cpp
          TreeNode* node=root->right;
          while (node->left!=NULL)
              node = node->left;
          root->val = node->val;
          root->right = deleteNode(root->right,node->val);
```
