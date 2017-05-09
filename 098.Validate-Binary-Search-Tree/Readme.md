### 98. Validate Binary Search Tree

BST的性质就是进行先序遍历的话，必然是第一个递增序列。

用DFS的方法，递归进行先序遍历。将读取的数值存入一个数组。当发现数组不满足升序时返回false
