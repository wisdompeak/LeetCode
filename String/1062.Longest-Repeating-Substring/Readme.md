### 1062.Longest-Repeating-Substring

#### 解法1： DP
此题和```1044.Longest-Duplicate-Substring```一模一样，唯一的区别是数据范围更小一些，因此可以用o(N^2)的DP算法。

我们将S分别看做S1和S2，那么此题就变成求两个字符串的longest common substring. 我们令dp[i][j]表示以S1[i]结尾、S2[j]结尾的最长的字符串的长度。则有状态转移方程：
```
if (S[i]==S[j]) dp[i][j] = dp[i-1][j-1] + 1;
```
特别注意，还要加上限制条件```if (i!=j)```

#### 解法2： Rolling Hash
High Level是二分搜值，猜测这个longest repeating substring的长度是多少。如果我们找不到任何长度为len的substring在S中出现过多次，那么就往下猜len；否则就往上猜len。

对于上述的子问题，我们会考虑一个固定长度len的滑窗，掠过整个S。在每个位置上的滑窗，我们都将里面的字符串映射成一个26进制的数，当做hash key放入集合中。如果发现这个key已经在集合中出现过，就意味着存在两个完全相同的子串。注意这个hash key会很大，所以需要取一个大数的模。当然，这肯定会有collision的风险。
