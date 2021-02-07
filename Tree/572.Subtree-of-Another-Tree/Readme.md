### 572.Subtree-of-Another-Tree

#### 解法1： 递归
判断s是否含有子树是t，先考虑s是否本身就是t：如果是的话直接返回true，如果不是的话就需要考察 isSubtree(s->left,t)||isSubtree(s->right,t)，注意相应的前提是左右子树非NULL。

对于判断两个数是否相等的函数 isSameTree(s,t)，就很好写了。

#### 解法2： KMP
我们将每棵树按照先序遍历转化为数组S和T，就可以映射为一个unique的序列。注意，对于任何的叶子节点，序列里也要包含它的两个空叶子（可以设计为INT_MAX）.

于是这道题就变成了在序列S里找一段和T一样的window。这就可以用到KMP算法。尽管这里的“目标串”和“模式串”都是数组而不是字符串，但并不妨碍KMP算法的实现：依旧是先计算模式串的自相关后缀数组，再计算S和T之间的互相关后缀数组。

#### 解法3： UID
参考```652.Find-Duplicate-Subtrees```的解法。先对s树的所有子树进行编号(包括key和ID），在已有的key2Id数据库的基础上，再对t树的所有子树用同样的法则进行编号。如果t树根节点的编号在数据库里出现了2次或以上，那么就说明t树必然在s树里出现过（因为t树里面不可能出现两个结构相同的、以t为根节点子树）。

[Leetcode Link](https://leetcode.com/problems/subtree-of-another-tree)
