### 959.Regions-Cut-By-Slashes

此题非常巧妙。我们将每一个格子都再细化为3*3的像素，那么“\”和“/”就各自变成了一条斜对角线。于是我们再看这个细化之后的3N*3N的矩阵，就会惊奇地发现，题目中定义的Regions此时都变成是像素联通的了。这就转换成了number of islands的题，用DFS,BFS或者Union Find都可以很轻松地解决。
