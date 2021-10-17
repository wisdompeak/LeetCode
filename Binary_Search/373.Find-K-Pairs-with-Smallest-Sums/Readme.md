### 373.Find-K-Pairs-with-Smallest-Sums

本题本质上非常巧妙地转换成了二维矩阵问题，同378。

设想一个MxN的矩阵，其矩阵元素(m,n)就是num1[m]+nums2[n]，很显然这个矩阵的行、列都是递增的。于是立刻就转化成了找该矩阵第k个元素的问题。

#### 解法1：BFS+PQ
用BFS的方法进行搜索。每次弹出一个PQ里最小的元素，然后新加入该元素相邻（右边和下边）的两个元素。最先弹出的k个元素就是答案。

#### 解法2：binary search + sorted matrix property
此题和378. Kth Smallest Element in a Sorted Matrix非常相似。

用binary search的方法先确定按从小到大顺序第k个元素是多少，令它为x。然后打印出matrix里面所有小于等于x的元素。注意，这样的元素可能会超过k个，也可能会小于k个。最终只要输出k个。


[Leetcode Link](https://leetcode.com/problems/find-k-pairs-with-smallest-sums)