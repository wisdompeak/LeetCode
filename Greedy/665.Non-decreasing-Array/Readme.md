### 665.Non-decreasing-Array

此题属于贪心法。考虑为了满足数列递增关系，遇到“坏点”的时候，最优的改动策略是什么。

#### 解法1

遍历数列一路查验是否递增，如果发现nums[i-1]>nums[i]，首先考虑的改动方案是将nums[i-1]=nums[i]，这样就避免改动nums[i]引发后续的变动。但是，如果又有nums[i-2]>nums[i]的话，那没有办法，为了避免改动两次，只能令nums[i]=nums[i-1]。此时计数1次。如果下次再出现了nums[i-1]>nums[i]的话，就返回false。

#### 解法2
遍历数列一路查验是否递增，如果发现nums[i-1]>nums[i]，说明坏点必然是nums[i-1]和nums[i]中间的一个。我们可以对其中一个进行隐去，看剩下的是否是non-decreasing序列。如果任意一个隐去后都不成立，就返回false。

[Leetcode Link](https://leetcode.com/problems/non-decreasing-array)
