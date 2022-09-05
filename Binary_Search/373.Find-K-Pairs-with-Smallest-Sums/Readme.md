### 373.Find-K-Pairs-with-Smallest-Sums

本题本质上非常巧妙地转换成了二维矩阵问题，同378。

设想一个MxN的矩阵，其矩阵元素(m,n)就是num1[m]+nums2[n]，很显然这个矩阵的行、列都是递增的。于是立刻就转化成了找该矩阵第k个元素的问题。

#### 解法1：BFS+PQ
用BFS的方法进行搜索。每次弹出一个PQ里最小的元素，然后新加入该元素相邻（右边和下边）的两个元素。最先弹出的k个元素就是答案。

注意搜索的过程中需要去重。去重得用map，因为用visited数组的话需要开辟太大的空间。

#### 解法2：binary search + sorted matrix property
此题和378, 668, 719, 1918都是一样的套路。

用binary search的方法先确定k-th smalletst elsment是多少，令它为x。然后遍历所有的nums1[i]，单调寻找满足```nums1[i]+nums2[j]<=x```的配对。

注意，这样的元素可能会超过k个，也可能会小于k个。最终只要输出k个。


[Leetcode Link](https://leetcode.com/problems/find-k-pairs-with-smallest-sums)
