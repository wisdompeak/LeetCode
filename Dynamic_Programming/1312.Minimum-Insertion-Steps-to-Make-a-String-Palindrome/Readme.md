### 1312.Minimum-Insertion-Steps-to-Make-a-String-Palindrome

这是一道经典题。我们将原数列s逆序得到t。本题就转化成了s和t各自最少加上多少字符使得两者相等。这是一个典型的双序列型的DP.令dp[i][j]表示总共需要加多少字符使得s[0:i]和t[0:j]相等。注意，最终s和t为了实现相等，所加的字符个数应该是一样的，故返回的答案应该是dp[n][n]/2。


[Leetcode Link](https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome)