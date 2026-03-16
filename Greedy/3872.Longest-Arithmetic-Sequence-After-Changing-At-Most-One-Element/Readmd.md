### 3872.Longest-Arithmetic-Sequence-After-Changing-At-Most-One-Element

我们很容易构造两个数组left和right。left[i]表示从i往左最多能组成多长的连续的等差数列。right[i]表示从i往右最多能组成多长的连续的等差数列。此时再用到题目给的条件：可以再任意改动一个数，所以任意的left[i]+1都可能是解。同理任意的right[i]+1也可能是解。

此时再考虑改动i，是否能从左边和右边延长得到等差数列。如果`nums[i+1]-nums[i-1]==2*(nums[i-1]-nums[i-2])`，那么意味着等差数列的长度可以增加left[i]。类似的如果`nums[i+1]-nums[i-1]==2*(nums[i+2]-nums[i+1])`，那么意味着等差数列的长度可以增加right[i]。

遍历所有的i，取全局最大值作为答案。
