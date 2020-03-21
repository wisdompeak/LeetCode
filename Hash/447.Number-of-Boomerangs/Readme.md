### 447.Number-of-Boomerangs

固定一个点i，查找其他所有点到该点的距离，存进一个Map。假设到i距离为d的点的数目有n个，说明有n*(n-1)个(i,j,k)配对。

因为(i,j,k)的次序有关系，遍历其他点的时候，要考察所有点而不是仅仅从i+1开始。


[Leetcode Link](https://leetcode.com/problems/number-of-boomerangs)