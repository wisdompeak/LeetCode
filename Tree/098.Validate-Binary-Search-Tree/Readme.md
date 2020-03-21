### 98. Validate Binary Search Tree

#### 方法1
BST的性质就是进行先序遍历的话，必然是第一个递增序列。

用DFS的方法，递归进行先序遍历。将读取的数值存入一个数组。当发现数组不满足升序时返回false

#### 方法2
满足BST的三个条件：
1. 左子树的最大值小于根节点，且右子树的最小值大于根节点
2. 左子树也是BST
3. 右子树也是BST

在判断第一个条件时，可以根据这个性质：左子树的最大值应该就是左子树最右下角的节点；右子树的最小值应该就是右子树最左下角的节点。

因此很容易写出递归判断的表达式。


[Leetcode Link](https://leetcode.com/problems/validate-binary-search-tree)