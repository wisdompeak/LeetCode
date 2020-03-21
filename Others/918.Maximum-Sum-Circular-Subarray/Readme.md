### 918.Maximum-Sum-Circular-Subarray

遇到循环数组的问题，有三种套路：

第一，分情况处理．类似的题有 213. House Robber II，分别考虑第一座房子是否抢劫．

第二，倍增，将原数组补到２倍的长度．

第三，取反．这样求跨越终端的maximum subarray，相当于求total sum - minimum subarray.

本题需要注意，因为我们求maximum subarray至少包含一个元素，所以在计算minimum subarray时，它不能包含所有的元素，但是它允许包含０个元素．所以在globalMin的初始值可以是0而不是INT_MAX．


[Leetcode Link](https://leetcode.com/problems/maximum-sum-circular-subarray)