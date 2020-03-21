### 450.Delete-Node-in-a-BST

1. 寻找要被删除的节点时，不着急利用BST的性质一下子循着key找出来，想办法用递归的形式去做。
```cpp
  if (key < root->val) 
  {
    root->left = deleteNode(root->left,key);
    return root;
  }
  else if (key > root->val) 
  {
    root->right = deleteNode(root->right,key);
    return root;
   }
```
2. 找到要被删除的节点时，一个非常迫切的问题是：如果把这个root删了，我应该把大于这个root的节点替代上去（以维持BST的性质）。但是这样又会造成右子树的结构变化，这种变化有可能很复杂。不着急，我们还是想办法搞成递归。我们不需要“删除”这个root，仅把root->val替换成仅大于root的那个节点（假设为node）的权值就可以了。那么右子树需要做什么变化呢？那就是在右子树中删除node（此时整棵树中相当于有两个node），这恰恰就是重复利用了deleteNode()函数的作用。
```cpp
else if (root->val==key)
{
	if (root->right==NULL)
        	return root->left;				
	else
    	{
        	TreeNode* node=root->right;
         	while (node->left!=NULL)
               		node = node->left;  // 找到那个仅大于root的那个节点node
         	root->val=node->val; // 替换root->val
         	root->right = deleteNode(root->right,node->val); // 递归处理右子树
         	return root;
    	}
}
```                


[Leetcode Link](https://leetcode.com/problems/delete-node-in-a-bst)