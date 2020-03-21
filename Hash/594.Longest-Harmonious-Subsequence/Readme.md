### 594.Longest-Harmonious-Subsequence

首先要正确理解题意。subsequence不一定要求连续，只要是原数列的任意部分都符合要求。

这样的话，我们可以遍历一遍整个数列，构造频次的Hash表，而且这个表是根据key有序排列的。那么我们可以依次考察任意相邻的两个频次，如果key值只相差1的话，那么这两个key对应的频次之和就是符合题意的一个方案。不断遍历这个Hash表、更新直到得到最大值。


[Leetcode Link](https://leetcode.com/problems/longest-harmonious-subsequence)