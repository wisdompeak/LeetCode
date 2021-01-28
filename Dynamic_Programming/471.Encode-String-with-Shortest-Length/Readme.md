### 471.Encode-String-with-Shortest-Length

令dp[i][j]表示区间s[i:j]可以encode的最短字符串。我们需要知道，对于任意区间s[i:j]，high level的encode方式有三类:
1. dp[i][j]就是s[i:j].
2. s[i:j]是若干个相同子串t的k次重复，每个子串长度是len，那么dp[i][j]可以写成```k[t]```的形式，注意t应该是dp[i][i+len-1]而不是原始的子串。另外，我们需要对k进行遍历得到最优的encode。
3. 我们还可以探索合适的切割点将dp[i][j]分为前后两部分，得到长度最优的```dp[i][j] = dp[i][k]+dp[k+1][j]```。

这是第二类区间型DP，动态规划的顺序是先小区间、后大区间。最终的答案就是dp[0][n-1].
