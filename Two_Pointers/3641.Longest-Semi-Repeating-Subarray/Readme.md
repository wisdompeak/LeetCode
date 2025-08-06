### 3641.Longest-Semi-Repeating-Subarray

非常明显的双指针，但是滑窗右边界j的控制需要格外小心。

对于任意的左边界i，当满足`while (j+1<n && count<=k)`时（count变量用于统计repeat元素的个数），说明可以将nums[++j]加入统计。如果循环退出，注意有两种不同情况：
1. 如果count>k，那么意味着j超出了合法的范围，合法subarray的长度最多是`j-i`.
2. 如果count<=k，那么意味着j已经到了最后一个元素(即n-1)但是仍未超出合法范围，故此时合法subarray的长度是`j-i+1`.
