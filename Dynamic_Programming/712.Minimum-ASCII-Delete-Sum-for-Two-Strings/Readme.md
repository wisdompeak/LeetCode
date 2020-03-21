### 712.Minimum-ASCII-Delete-Sum-for-Two-Strings

对于此类有两个字符串、求最终使得彼此相同的操作的题目，一个典型的DP算法套路就是：设置状态数组dp[i][j]，代表s1前i个字符、s2前j个字符时的目标值。考虑dp[i][j]和dp[i-1][j-1]、dp[i-1][j]、dp[i][j-1]的递推关系。

当s1[i]==s2[j]时，说明不需要删减任何字符，即能由状态(i-1,j-1)到(i,j)，即 dp[i][j]==dp[i-1][j-1]。

当s1[i]!=s2[j]时，可以从状态(i-1,j)通过删减s1[i]到(i,j)，或者才从状态(i,j-1)通过删减s2[j]到(i,j)，所以 dp[i][j]= min (dp[i-1][j]+s1[i], dp[i][j-1]+s2[j])

另外需要特别注意边界条件dp[0][j]和dp[i][0]。

类似此题的还有：583	Delete Operation for Two Strings，97	Interleaving String，72	Edit Distance


[Leetcode Link](https://leetcode.com/problems/minimum-ascii-delete-sum-for-two-strings)