### 1092.Shortest-Common-Supersequence

#### 解法1：直接考虑“最短公共超串”
如果只是问Shortest-Common-Supersequence的长度,那么就是一道非常基本的dp题,典型的"two string conversion"的套路.

现在要求打印出这样的Shortest-Common-Supersequence,无非就是从dp[M][N]逆着往回走,每一步我们都需要判断dp[i][j]之前的状态是什么?其实就是重复一遍给dp赋值的逻辑:
1. 如果dp[i][j]是由dp[i-1][j-1]+1得来,也即是说str1[i]==str2[j]，那么就意味着当时在构建SCS的时候，最后一步是在dp[i-1][j-1]的基础上加上str1[i](或者str2[j])
2. 如果dp[i][j]是由dp[i-1][j]+1得来,那么说明当时是在dp[i-1][j]的基础上加上str1[i]，现在逆序重构的时候需要先加上str1[i].
3. 如果dp[i][j]是由dp[i][j-1]+1得来,那么说明当时是在dp[i][j-1]的基础上加上str2[j]，现在逆序重构的时候需要先加上str2[j].

这样一直回退到```i==0 && j==0```

#### 解法2：直接考虑“最长公共子串”
此题还可以先解决一个最长公共子串问题（LCS），求得二维数组dp[i][j]，然后根据这个dp的定义来重构超级串。

同样，我们逆序构造这个超级串：
1. 如果dp[i][j]是由dp[i-1][j-1]+1得来,也即是说str1[i]==str2[j]，那么就意味着当时在构建SCS的时候，是在dp[i-1][j-1]的基础上加上```str1[i]```(或者```str2[j]```).
2. 如果dp[i][j]是由dp[i-1][j]得来,也即是说str1[i]不是属于这个LCS的一部分，那么现在构造SCS的时候，先把它加上。
3. 如果dp[i][j]是由dp[i][j-1]得来,也即是说str2[j]不是属于这个LCS的一部分，那么现在构造SCS的时候，先把它加上。

[Leetcode Link](https://leetcode.com/problems/shortest-common-supersequence)
