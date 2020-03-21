### 333.Largest-BST-Subtree

首先，看清题意，A subtree must include all of its descendants.

要判断一个root是否代表了一颗BST，有三个条件：    
1. 其左子树也是BST（或者NULL）
2. 其右子树也是BST（或者NULL）
3. 其根节点小于左子树的最大值，并且根节点大于右子树的最小值。

接下来，考虑这个问题其实包括了两个任务：判断BST，以及它有多少个节点数目。怎么合并一起写这个DFS(root)递归函数呢？很容易想到这样的设计：当root是BST时返回其包含的节点数目，当root不是BST时则返回-1. 这个-1的返回值可以帮助上一级的根节点确定非BST，一举两得。

首先,边界条件：if (root==NULL) return 0. 认为是BST，但节点数目为0。

其次，对于非NULL的节点，我们就可以放心地为左右子树分别递归调用了
```cpp
int leftNum = DFS(root->left);
int rightNum = DFS(root->right);
```
leftNum和rightNum有任何一个为-1，都表明root都不是BST。

此外，判断root为BST的第三个条件，等价于这样的操作：将左子树的右下节点与根节点比较、右子树的左下节点与根节点比较。设计一个while语句就可以迅速定位所需要的边界节点。

以上三个条件都判断后，如果root不是BST，返回-1；如果是BST，返回leftNum+rightNum+1.


[Leetcode Link](https://leetcode.com/problems/largest-bst-subtree)