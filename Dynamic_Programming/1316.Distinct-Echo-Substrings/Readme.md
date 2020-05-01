### 1316.Distinct-Echo-Substrings

本题其实很简单。定义dp[i][j]表示以i结尾的substring和以j结尾的substring最长有多少字符是相同的。这是一个非常基础的动态规划。

如果发现dp[i][j]>=j-i，那么就说明text[i+1:j]就是符合要求的echo substring的一半。统计个数的时候我们再用一个set来去重就行。
