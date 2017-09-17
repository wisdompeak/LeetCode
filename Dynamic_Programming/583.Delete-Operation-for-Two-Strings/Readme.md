### 583.Delete-Operation-for-Two-Strings

此题的本质是LCS(longest common sequence)，需要用dp算法。

Dp[i][j]表示word1的前i个元素、word2的前j个元素的最长共同元素数目。

递推关系：```dp[i][j]=dp[i-1][j-1]+1 (if word1[i]==word2[j]) 或 max(dp[i-1][j],dp[i][j-1]) (if word1[i]!=word2[j])```
