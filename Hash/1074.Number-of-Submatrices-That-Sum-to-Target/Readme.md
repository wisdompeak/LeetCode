### 1074.Number-of-Submatrices-That-Sum-to-Target
基本思想：固定上、下界的位置，在纵方向上累加每列，可以得到一个一维数组。然后从左到右逐个扫描求presum，并放入一个Hash表中。查看当前的presum-target是否已经在hash表中。存在的话就说明有submatrix的和等于target。

时间复杂度：```o(N^3)```


[Leetcode Link](https://leetcode.com/problems/number-of-submatrices-that-sum-to-target)
