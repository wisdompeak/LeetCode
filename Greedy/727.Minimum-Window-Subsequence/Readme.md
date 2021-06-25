### 727.Minimum-Window-Subsequence

#### 解法1：双序列DP
对于双字符串的题目，双序列DP是一个非常自然的思路。根据双序列DP的套路，我们定义dp[i][j]表示，截止到S[i]的最短的substring长度，使得T[1:j]是这个substring的subsequence。注意，这个substring一定要包括S[i]本身。也就是说，如果这个dp的值是k，那么要求T[1:j]是S[i-k+1:i]的一个subsequence。

最终的答案是 min {dp[i][N]} (i=1,2,...M)。

根据双序列DP的套路，转移方程的入手点就是观察S[i]和T[j]的关系。
```cpp
for (int i=1; i<=M; i++)
 for (int j=1; j<=N; j++)
 {
    if (S[i]==T[j])
       dp[i][j]=dp[i-1][j-1]+1;
    else
       dp[i][j]=dp[i-1][j]+1; //说明S[i]对于构建T[1:j]没有帮助，T[1:j]得从dp[i][j-1]里面找
 }
```
然后我们考虑边界条件。易知 dp[0][j] (i=0, j=1,2,...N) 都是需要定义的边界条件。长度为0的S子串肯定不会是T的supersequence。故这些初始值应该是INT_MAX.

其次可以看出 dp[i][0] (i=0,1,2,...,M)也是需要提前设置初始值。显然，长度为0的T子串是任何长度为0的S子串的subsequence，故初始值是0.

最后在所有dp[i][N]中找到第一个最小值k，那么 S.substr(i-k+1,k)就是答案。

显然时间复杂度是o(MN).

#### 解法2：状态机
其实只要确定T[0]在S中的位置（比如说是start），那么T在S里的superstring就可以唯一地用贪心法确定。简单的方法就是双指针：S的指针指向start，T的指针指向0，S的指针一直向右遍历，试图去匹配T里面的每一个字符。如果T能够扫描完每一个字符，那么S指针的位置就是这个superstring的结尾。这样的做法复杂度是```(M+N)*K```，其中K是T[0]在S中出现的次数。

也可以利用类似```LC 792```的状态机的做法。提前对S预处理得到next[i][ch]，表示在S串的i位置上向右看，第一个出现ch的位置。这样我们就可以用o(1)时间实现S指针的跳转。这样的做法时间复杂度是```N*K```.


[Leetcode Link](https://leetcode.com/problems/minimum-window-subsequence)
