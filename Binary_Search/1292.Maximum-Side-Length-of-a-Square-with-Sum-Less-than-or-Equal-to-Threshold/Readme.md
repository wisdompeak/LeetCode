### 1292.Maximum-Side-Length-of-a-Square-with-Sum-Less-than-or-Equal-to-Threshold

本题可以遍历每个方阵，查看方阵的和sum是否满足条件。这样的时间复杂度是o(N^4)，其中遍历每个元素作为方阵的右下角需要o(N^2)，随着边长的增长，面积增长的速率是o(N^2)。

本题更高效的方法就是二分搜值。猜测一个边长len，查看是否有一个方阵的sum满足条件。这样的时间复杂度是```o(logN*N^2)```.

注意，本题中计算任意一个方阵的元素sum的复杂度是o(1)，因为只要提前计算二维的前缀和presum[i][j]即可。例如，以(a,b)为左上角、(x,y)为右下角的矩阵，其元素和就是```presum[x][y]-presum[i-1][y]-presum[i][y-1]+presum[i-1][j-1]```.
