### 456.132-Pattern

从后往前遍历。我们假设当前的元素nums[i]是132 pattern中的"2"，那么什么元素最适合作为"3"呢？其实就是"2"的prev greater element，也就是nums[i]左边第一个比它大的元素，假设是nums[j]。为什么这样的j最合适呢？因为j越接近i的话，我们就能够在[0,j-1]的区间里找到一个越小的数作为132 pattern里的"1"，即越容易收集齐这样的132 pattern。

具体的做法是，我们先预处理数组，算出每个元素k左边的最小值leftMin[k]。然后从后往前遍历，对于第i个元素，找到它的prev greater element，它的index记做j，那么查看leftMin[j]的元素是否比num[i]还小。如果符合要求，就可以返回true.

[Leetcode Link](https://leetcode.com/problems/132-pattern)
