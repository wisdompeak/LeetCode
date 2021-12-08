### 687.Longest-Univalue-Path

此题和```543. Diameter of Binary Tree```很相似。设计DFS(node)函数，返回的是以node为起点，朝某个单向下行最长的Univalue path

每一次调用DFS(node)，都要先调用L=DFS(node->left)和R=DFS(node->right)，将左右节点都递归遍历完毕。

如果左节点、当前节点、右节点的数值相等，说明可以形成一个完整的uniValuePath，用Ｌ＋Ｒ＋１来刷新全局的longest变量。

那么考虑DFS(node)自己的返回值是什么呢？显然是１，或Ｌ＋１（如果根与左节点相同），或Ｒ＋１（如果根与右节点相同）


[Leetcode Link](https://leetcode.com/problems/longest-univalue-path)
