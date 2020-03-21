### 532.K-diff-Pairs-in-an-Array

#### 解法1：
双指针，滑动窗口，时间复杂度o(nlogn)。需要注意的是，每移动一次左指针后，右指针的初始位置必须保证在左指针的右边。

#### 解法2：
Hash表。设置两个集合，遍历nums，用集合A装每次访问的元素nums[i]，用集合B装用nums[i]构成pair的较小的那个元素。最后数一下集合B中的元素个数就是答案。


[Leetcode Link](https://leetcode.com/problems/k-diff-pairs-in-an-array)