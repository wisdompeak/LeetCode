### 1639.Number-of-Ways-to-Form-a-Target-String-Given-a-Dictionary

此题有点类似1621的感觉。令dp[i][k]表示我们只构建构建target[0:i]，并且最多用到dictionary里面（所有词）的第k个字母，有多少种方案。根据套路，突破口依然是target的第i个字母、词库里的第k个字母。

首先，第一种情况是，target[0:i]的选择根本不考虑词库里的第k个字母，完全靠第0~k-1个字母来构造，那么就有```dp[i][k] = dp[i][k-1]```。

第二种情况是，如果词库里有一些单词的第k个字母与target[i]相同，那么我们可以考虑target[i]用它们来构造，因此有额外的方案```dp[i][k] += dp[i-1][k-1]*count[k]```，其中count[k]表示词库里有多少单词的第k个字母与target[i]相同。

最终的答案就是dp[n][m]. 其中n是target的长度，m是词库里最长的单词长度。
