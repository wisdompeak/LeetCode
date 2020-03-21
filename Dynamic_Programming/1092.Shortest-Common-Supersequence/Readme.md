### 1092.Shortest-Common-Supersequence

如果只是问Shortest-Common-Supersequence的长度,那么就是一道非常基本的dp题,典型的"two string conversion"的套路.

现在要求打印出这样的Shortest-Common-Supersequence,无非就是从dp[M][N]逆着往回走,每一步我们都需要判断dp[i][j]之前的状态是什么?其实就是重复一遍给dp赋值的逻辑:
1. 如果dp[i][j]之前的状态是dp[i-1][j-1],那么就是在dp[i-1][j-1]的基础上加上str1[i](或者str2[j])
2. 如果dp[i][j]之前的状态是dp[i-1][j],那么就是在dp[i-1][j]的基础上加上str1[i]
3. 如果dp[i][j]之前的状态是dp[i][j-1],那么就是在dp[i][j-1]的基础上加上str2[j]

这样一直回退到```i==0 && j==0```


[Leetcode Link](https://leetcode.com/problems/shortest-common-supersequence)