### 687.Longest-Univalue-Path

设计DFS函数，返回的是以root为起点，朝某个单向下行最长的Univalue path

每一次调用DFS(node)，都要先调用DFS(node->left)和DFS(node->right)，然后进一步判断DFS(node)的返回值，并不断刷新result.
