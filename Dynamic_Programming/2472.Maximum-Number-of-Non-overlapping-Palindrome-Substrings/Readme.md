### 2472.Maximum-Number-of-Non-overlapping-Palindrome-Substrings

令dp[i]表示s[0:i]里面的the maximum number of palindrome substrings. 显然，转移方程的突破口在于最后一个回文子串。如果最后一个回文子串不包括s[i]，那么有`dp[i] = dp[i-1]`，如果最后一个回文子串包括s[i]，那么我们就需要找这个回文子串的起始位置j，然后`dp[i] = dp[j-1] + 1`. 这样的j可能有多个，根据数据量，从[0:i]遍历一遍都是可行的。

另外，我们需要用o(N^2)的时间提前处理得到一个数组isPalin[i][j]，来记录s[i:j]是否是一个回文串。这个技巧已经出现过很多次了。
