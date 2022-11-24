### 2478.Number-of-Beautiful-Partitions

本题很容易想到常规的N^3的动态规划。令dp[i][j]表示前i个元素（1-index）分成j份的最优方案（即最多的切分数）。显然，我们关注的就是最后一个subarray的位置。如果i是合数，那么我们可以遍历所有i之前的位置k，如果满足`isprime(k)`, `!isprime(k+1)`，`i-k>=minLength`，那么就意味着我们可以在k后面切一刀，[k+1,i]作为最后一段。于是就有`dp[i][j] += dp[k][j-1]`。

代码如下：
```cpp
for (int i=1; i<=n; i++)
  for (int j=1; j<=K; j++)
  {
      if (isprime(s[i])) {
          continue;
      }
      for (int k=j; (k+minLength-1)<=i; k++)
      {
          if (isprime(s[k]))
              dp[i][j] += dp[k-1][j-1];
      }
  }
```

那么如何改进时间复杂度呢？我们观察这个状态转移方程，发现无论i是多少，dp[i][j]只与`sum{dp[k][j-1]}`有关，其中k是比i小的数。所以我们可以把j放在第一个循环（前两个循环互换没有任何影响），然后随着i的遍历，我们可同时累加与更新`sum{dp[k][j-1]}`得到一段适当的前缀和，这样直接就有`dp[i][j] = presum`即可。

于是改动后的代码
```cpp
for (int j=1; j<=K; j++)
{
    LL sum = 0;
    for (int i=1; i<=n; i++)            
    {    
        if (i-minLength>=0 && !isprime(s[i-minLength]) && isprime(s[i-minLength+1]))
        {
            sum += dp[i-minLength][j-1];
            sum %= M;
        }
        if (!isprime(s[i])) {
            dp[i][j] = sum;                    
        }                
    }
}
```
最后答案是dp[n][K]。
