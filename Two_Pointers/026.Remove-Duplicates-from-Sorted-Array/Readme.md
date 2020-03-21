### 26. Remove Duplicates from Sorted Array

注意去除重复元素后仍然要求保持原始顺序，必须in-place实现，故考虑快慢双指针。

遍历快指针，将快指针所指向的所有有效元素都移动到左指针的位置上。

对于快指针经过的所有重复元素则continue。重复元素的判定方法是比较nums[right]==nums[left]（或者nums[right]==nums[right-1]，取决于left和right的初始状态）。

最后输出左指针的位置，因为如前所述，所有的有效元素都已经在左指针上了。


[Leetcode Link](https://leetcode.com/problems/remove-duplicates-from-sorted-array)