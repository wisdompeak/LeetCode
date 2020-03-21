### 655.Print-Binary-Tree

先求出这棵树的高度height，那么整个结果矩阵的宽度就是 pow(2,height)-1.

如何填充这个矩阵数组呢？要利用每个父节点在下一层的相对位置，是其所有子节点的最中央的特点，用DFS来做。设置每一层的start和end，找到mid的位置放置父节点的值。则左子树在下一层的摆放区间就在start\~mid-1，右子树在下一层的摆放区间就在mid+1\~end.如此就可以设置递归函数。


[Leetcode Link](https://leetcode.com/problems/print-binary-tree)