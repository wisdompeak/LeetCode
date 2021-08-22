### 1977.Number-of-Ways-to-Separate-Numbers

将连续的字符串划分成若干个数字组成的序列，相当于“划分区间”。如果令dp[i]表示前i个字符能组成的递增序列的方案数，那么突破口就是最后一个数字（也就是区间）的范围。这就联想到了第一类区间型DP。我们令dp[i][len]表示由前i个字符组成、且最后一个数字的字符长度是len的递增序列的方案数。
```
X X X (X X X X) [X X X X]
       k        j      i
```
在上面的例子中，令```j = i-len+1```，那么[j:i]就是最后一个元素（记做Z）。根据规则，我们需要倒数第二个元素（记做Y）小于等于Z。我们发现y的起始位置有多种可能。当k=j-1的时候，显然Y会小于Z，所以属于dp[k][j-k]的任何方案，都可以加上Z，继续构成dp[i][len]的方案。同理，当k=j-2的时候，也是成立的。显然，k可以不停前移，一直到```k = j-len```的时候打住，因为我们并不能确认此时的Y和Z是否依然是递增的（因为位数相同）。所以综上
```
dp[i][len] = sum {dp[j-1][len2]} for len2 = 1, 2, 3, ... , len-1, (len) ?
```
其中len2是否能取到len，取决于```[j-len: j-1]```与```[j:i]```孰大孰小。

所以大致的状态转移方程：
```cpp
for (int i=0; i<n; i++)
  for (int len=1; len<=i+1; len++)
  {
      int maxLen2 = len-1;
      if (s[j-len:j-1] <= s[j:i])
        maxLen2++;
      for (int len2 = 1; len2 <= maxLen2; len2++)
        dp[i][len] += dp[j-1][len2];
  }
```

此时我们发现这段代码需要三重循环，时间复杂度是N^3，会TLE。那么该如何优化呢？我们发现最内层的循环其实是dp[j-1][x]的一个前缀和```presum_dp[j-1][maxLen2]```，所以可以改写成
```cpp
for (int i=0; i<n; i++)
  for (int len=1; len<=i+1; len++)
  {
      int maxLen2 = len-1;
      if (s[j-len:j-1] <= s[j:i])
        maxLen2++;
      dp[i][len] += presum_dp[j-1][maxLen2];
  }
```

我们接着发现，我们永远是拿pre_dp给dp赋值。说明其实我们需要不停更新的是pre_dp. 所以计算得到的dp[i][len]要回馈给pre_dp. 并且len本身就是从小到大遍历的，所以我们同样构建dp[i][x]的前缀和。所以继续改写：
```cpp
for (int i=0; i<n; i++)
  for (int len=1; len<=i+1; len++)
  {
      int maxLen2 = len-1;
      if (s[j-len:j-1] <= s[j:i])
        maxLen2++;
      dp[i][len] += presum_dp[j-1][maxLen2];
      presum_dp[i][len] = presum_dp[i][len-1]+dp[i][len];
  }
```
所以这道题本质上的需要更新的状态变量不是dp[i][len]，而是presum_dp[i][len]. 而dp只是一个临时变量而已。

此时的代码看上去是二重循环了。但是其中有一个细节还需要优化：如何判断两个长度相同的字符串```s[j-len:j-1]```和```s[j:i]```谁大谁小？如果挨个字符检查一遍，就又要o(N)的复杂度。怎么优化呢？很巧妙，我们用o(N^2)的时间提前计算s里面任意两个位置a,b的longest common substring。有了lcs[a][b]的数据，那么对于两个字符串```s[j-len:j-1]```和```s[j:i]```，我们可以跳过前面的相同字符，直接定位到```j-len+lcs[j-len][j]```和```j+lcs[j-len][j]```这两个有着不同字符的位置，看看此处的字符谁大谁小即可。

最终输出的答案是```presum_dp[n-1][n]```
