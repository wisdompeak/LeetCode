### 1682.Longest-Palindromic-Subsequence-II

在```516.Longest-Palindromic-Subsequence```中我们采用区间型dp，令dp[i][j]表示区间[i:j]内的最长回文长度。在本题为了解决“相邻的嵌套pair不能相同的问题”，我们定义dp[i][j][k]表示区间[i:j]内、最外层是字母k的最长回文长度。

如何更新dp[i][j][k]呢？我们不着急思考k。我们先想一下区间[i:j]，如果s[i]==s[j]==a的话意味着什么呢？我们对于dp[i][j][k]的更新分为三类：
1. dp[i][j][a]就可以更新为```max{dp[i+1][j-1][kk]+2} for kk!=a```. 
2. 对于k!=a的字母，dp[i][j][k]可以更新为dp[i+1][j-1][k]，这是因为最外层{i,j}肯定不会贡献一对k，故可以直接剥去。

如果s[i]!=s[j]的话，令s[i]=a, s[j]=b，那么dp[i][j][k]的更新同样分为三类：
1. dp[i][j][a] = dp[i][j-1][a]，因为元素j不会提供字母a。
2. dp[i][j][b] = dp[i+1][j][a]，因为元素i不会提供字母b。
3. for k!=a && k!=b 的字母, 我们有 dp[i][j][k] = dp[i+1][j-1][k]，因为最外层{i,j}肯定不会贡献一对k

综上，时间复杂度是```O(N^2*26)```
