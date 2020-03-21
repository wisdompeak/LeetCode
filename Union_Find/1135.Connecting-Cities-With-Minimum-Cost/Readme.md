### 1135.Connecting-Cities-With-Minimum-Cost

本题的本质是构造一个最小生成树．一个比较简单的算法就是Kruskal算法，本质就是贪心＋Union Find．

按照边的权重顺序（从小到大）将边加入生成树中，但是若加入该边会与生成树形成环则不加入该边。直到树中含有V-1条边为止。这些边组成的就是该图的最小生成树。

Kruskal算法的时间复杂度为 ElogE。 


[Leetcode Link](https://leetcode.com/problems/connecting-cities-with-minimum-cost)