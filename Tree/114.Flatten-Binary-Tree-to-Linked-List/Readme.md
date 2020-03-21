### 114.Flatten-Binary-Tree-to-Linked-List

用递归的思路。先各自flattern(root->left)和flattern(root->right)将左右子树分别扁平化。然后进入左子树一路向右找到最底层的节点node。将整颗右子树拼接到node->right，再把整颗左子树拼接到root->right。

最后重点，不要忘了把 root->left=NULL


[Leetcode Link](https://leetcode.com/problems/flatten-binary-tree-to-linked-list)