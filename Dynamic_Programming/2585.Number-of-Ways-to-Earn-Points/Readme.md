### 2585.Number-of-Ways-to-Earn-Points

非常常规的背包DP。将第二个下标设计为已经取得的分数。令dp[i][j]表示前i种题目里恰好取得j分的方案数。对于每种题目类型，我们尝试取不同的数目k。所以总共三层循环。比如，当第i种题目取k道题时，那么方案就取决于前i-1中题目里取`j- k*types[i][1]`分的方案数。
```cpp
for (int i=1; i<=n; i++)
  for (int j=0; j<=target; j++)
  {
      for (int k=0; k<=types[i][0]; k++)
      {
          if (k*types[i][1]>j) break;
          dp[i][j] += dp[i-1][j- k*types[i][1]];
          dp[i][j] %= M;
      }
  }
```
