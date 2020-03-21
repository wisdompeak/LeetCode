### 240.Search-a-2D-Matrix-II
非常巧妙的解法：从矩阵的左下角出发，如果比target小则右移，如果比target大则上移，直至找到target或者出界。

这个方法可以用到所有基于这种矩阵的题目，比如373和378，就是配合二分法可以得到更高效的解。


[Leetcode Link](https://leetcode.com/problems/search-a-2d-matrix-ii)