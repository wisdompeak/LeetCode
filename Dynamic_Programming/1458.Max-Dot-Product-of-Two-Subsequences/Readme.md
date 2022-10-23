### 1458.Max-Dot-Product-of-Two-Subsequences

这是一道典型的双序列型的DP。令dp[i][j]表示A序列的前i个元素、B序列的前j个元素，可以得到的最大点乘结果。突破口就是看A[i]和B[j]。

1. A[i]和B[j]组成一对，那么dp[i][j] = dp[i-1][j-1]+A[i]*B[j]。注意，当dp[i-1][j-1]<0时，该项其实应该略去，即dp[i][j] = A[i]*B[j].
2. A[i]和B[j]不组成一对，那么这两个元素必然至少有一个不会被用来参与点乘。所以dp[i][j] = max{dp[i-1][j], dp[i][j-1]}.

最终的答案是dp[m][n].
