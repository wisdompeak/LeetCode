### 572.Subtree-of-Another-Tree

判断s是否含有子树是t，先考虑s是否本身就是t：如果是的话直接返回true，如果不是的话就需要考察 isSubtree(s->left,t)||isSubtree(s->right,t)，注意相应的前提是左右子树非NULL。

对于判断两个数是否相等的函数 isSameTree(s,t)，就很好写了。


[Leetcode Link](https://leetcode.com/problems/subtree-of-another-tree)