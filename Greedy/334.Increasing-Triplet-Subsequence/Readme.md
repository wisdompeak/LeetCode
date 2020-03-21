### 334.Increasing-Triplet-Subsequence

#### 解法1：
从左往右，从右往左，各扫一遍数组，计算每个元素的LeftMin和RightMax。那么只要LeftMin[i]<nums[i]<RightMax[i]即可找到一对triplet

这样的话，时间是o(3N),空间是o(2N)

#### 解法2：
非常巧妙的思维，本题即是在这个数组里找到长度为3的increasing subsequence即可！

用一个数组来记录当前的递增序列，长度达到3即可停下来。时间最差是nlog(3)，空间是o(3)。


[Leetcode Link](https://leetcode.com/problems/increasing-triplet-subsequence)