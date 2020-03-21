### 397.Integer-Replacement

仔细分析一下就能发现，这题无法用DP做，因为对DP数组无法找到合适的遍历顺序。

用递归做就能通过，也非常简单。但要注意 n=INT_MAX时的越界问题。


[Leetcode Link](https://leetcode.com/problems/integer-replacement)