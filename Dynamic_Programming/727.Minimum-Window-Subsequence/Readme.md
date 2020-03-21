### 727.Minimum-Window-Subsequence

对于双字符串的DP题，如果没有其他思路，不妨就考虑dp[i][j]代表了字符串A的前i个、字符串B的前j个的子问题，很大概率上就可以成功。

在本题中，我们令 dp[i][j] 表示字符串T子串（1\~i）是字符串S子串（1\~j）的subsequence的、最小的S串长度，这个长度必须要从S串的j位置往前算起。最终的答案是在dp[N][j] (j=1,2,...M)中找最小的。

和很多字符串的DP题一样，动态转移方程很套路，根据 T[i]==S[j]分别考虑即可：
```cpp
for (int i=1; i<=N; i++)
 for (int j=1; j<=M; j++)
 {
    if (T[i]==S[j])
       dp[i][j]=dp[i-1][j-1]+1;
    else
       dp[i][j]=dp[i][j-1]+1; //说明S[j]没有帮助，还要依靠dp[i][j-1]
 }
```
然后我们考虑边界条件。易知 dp[0][j] (i=0, j=1,2,...M) 都是要考虑的。长度为0的T子串肯定是任意S子串的subsequence。故这些初始值应该是0.

另外可以看出 dp[i][0] (i=1,2,...,N, j=0)也是需要提前设置初始值。显然，长度不为0的T子串不是任何空字串的subsequence，故这些值应该是inf.

最后在所有dp[N][j]中找到第一个最小值k，那么 S.substr(j-k+1,k)就是答案。


[Leetcode Link](https://leetcode.com/problems/minimum-window-subsequence)