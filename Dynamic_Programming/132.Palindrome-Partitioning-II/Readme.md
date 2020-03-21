### 132.Palindrome-Partitioning-II

这是一道分两步走，并且每一步都可以用DP实现的题目。

首先，我们可以用dp来计算任意两个字符之间是否是回文的。转移方程是：```isPal[i][j] = 1 if isPal[i+1][j-1]==1 and s[i]==s[j]```

接下来，我们可以用dp来计算第二个问题。令dp[i]表示从0到i的字符串可被拆分为最少的回文数的个数。则易知```dp[i] = min(i+1,dp[j]+1 for isPal[j+1][i]==1)```


[Leetcode Link](https://leetcode.com/problems/palindrome-partitioning-ii)