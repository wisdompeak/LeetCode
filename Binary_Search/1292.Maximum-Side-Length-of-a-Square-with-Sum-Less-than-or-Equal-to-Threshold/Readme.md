### 1292.Maximum-Side-Length-of-a-Square-with-Sum-Less-than-or-Equal-to-Threshold

本题可以遍历每个方阵，查看方阵的和sum是否满足条件。这样的时间复杂度是o(N^3)，其中遍历每个元素作为方阵的右下角需要o(N^2)，探索不同的边长需要o(N)。

本题更高效的方法就是二分搜值。猜测一个边长len，查看是否有一个方阵的sum满足条件。这样的时间复杂度是o(logN*N^2).

注意，本题中计算一个方阵的sum的方法可以是o(1)，只要提前计算所有(0,0)到(i,j)的矩阵和presum[i][j]。
