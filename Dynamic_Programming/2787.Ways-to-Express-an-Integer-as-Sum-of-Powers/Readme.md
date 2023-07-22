### 2787.Ways-to-Express-an-Integer-as-Sum-of-Powers

#### 解法1：
令dp[i][j]表示数字i可以分解的方案数目，并且要求分解出的最大的因子不能超过j。

如果该分解不包含`j^x`，那么就有`dp[i][j] = dp[i][j-1]`; 如果该分解包含了`j^x`，并且`i>=j^x`，则有`dp[i][j] = dp[i-j^x][j-1]`. 两者之后即是dp[i][j]。

最终答案是dp[n][n].

#### 解法2：
令dp[i]表示数字i可以分解的方案数目。

我们从小到大依次考虑因子1,2,3,...n的使用。当可以使用j^x时，所有的dp数列可以更新：`dp_new[i] = dp_old[i] + dp_old[i-j^x]`. 这样刷新n遍dp数组，最终的答案是dp[n].
