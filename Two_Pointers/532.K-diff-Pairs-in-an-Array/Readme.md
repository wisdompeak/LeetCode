### 532.K-diff-Pairs-in-an-Array

最简单的思路应该就是用双指针来做。

将nums排序后，对应一个前指针i，移动后指针j查看是否有 nums[i]+k==nums[j]。如果有，则计数器加1.

为了避免重复，保证前指针i跳过重复的元素。

另外注意的一个细节就是，每确定一个指针i，都要重新定位j=i+1.


[Leetcode Link](https://leetcode.com/problems/k-diff-pairs-in-an-array)