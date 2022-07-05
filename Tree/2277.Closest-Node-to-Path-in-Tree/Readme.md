### 2277.Closest-Node-to-Path-in-Tree

本题的时间复杂度要求是o(N^2)，所以常规解法是，从node开始dfs得到所有节点到node的距离dist2node。然后从start开始dfs整棵树，对于能够通往end的这个分支上的节点，取最小的dist2node。

本题还有一种比较精彩的解法。先遍历所有的点作为起点，dfs整棵树，这样得到全局的matrix[i][j]表示任意两点之间的距离。然后对于start，我们遍历它的邻居j，发现如果有```matrix[start][end]==matrix[j][end]+1```，说明j是位于从start到end的路径上。依次递归下去，就能直接从start走向end，沿途中取最小的matrix[j][node].
