### 611.Valid-Triangle-Number

最佳的解法是用双指针。

将nums排序后，固定最大的位置k，则前两个元素的位置i,j需要满足其nums[i]+nums[j]>nums[k]，等效于一道“2sum larger”的题目，于是双指针的移动规则就非常清楚了。


[Leetcode Link](https://leetcode.com/problems/valid-triangle-number)