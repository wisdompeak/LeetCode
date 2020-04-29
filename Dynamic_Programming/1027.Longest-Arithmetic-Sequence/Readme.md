### 1027.Longest-Arithmetic-Sequence

我们考虑对于任意的nums[i]，当它作为某个等差数列的某一项时，它的左边紧邻的一项会是谁？感觉任何j<i的nums[j]其实都可以是候选。因此我们可以遍历i和j，确定i和j之后就可以知道公差diff=nums[i]-nums[j]，于是我们就可以追问：当nums[j]作为公差为diff的等差出列的一员时，在它之前有多长？如果dp[j][diff]表示截止到nums[j]时，公差为diff的等差数列的长度，那么显然dp[i][diff] = dp[j][diff]+1. 于是我们就很容易地得到了状态转移方程。

因此，我们设计的数据结构是```vector<unordered_map<int,int>>dp```,diff作为dp[i]这个Hash表的key，dp[i][diff]就是这个Hash表的value表示长度。

特别注意，如果dp[j][diff]==0，说明nums[j]之前并没有任何元素与nums[j]构成公差为diff的数列，所以这种情况下dp[i][diff]就应该是2（即nums[i],nums[j]组成一个等差数列）而不是1.

此题的思想和```446.Arithmetic-Slices-II-Subsequence```解法1一致。

本题可以有一个follow up：如果给出的数组是一个集合而不是给定顺序的数组，那么答案会是多少？这样的解法就完全不同了。可以参见 https://github.com/wisdompeak/LintCode/tree/master/Two_Pointers/1488.Longest-Sequence


[Leetcode Link](https://leetcode.com/problems/longest-arithmetic-sequence)
