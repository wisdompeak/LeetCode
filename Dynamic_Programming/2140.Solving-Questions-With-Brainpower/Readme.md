### 2140.Solving-Questions-With-Brainpower


#### 解法3 （错误）
令dp[i]表示处理前i个元素能取得的最大值。
```cpp
for (int i=0; i<n; i++)
    dp[i] = questions[i][0];
for (int i=0; i<n; i++)
{
    int skip = questions[i][1];
    if (i+1<n)
        dp[i+1] = max(dp[i+1], dp[i]);
    if (i+skip+1<n)
        dp[i+skip+1] = max(dp[i+skip+1], dp[i] + questions[i+skip+1][0]);
    ret = max(ret, dp[i]);
}
```
其中的问题在于，有这么一种情况：dp[i]对应着本身没有取第i个元素，因此它的值来源于dp[i-1]；同时dp[i-1]对应着取了第i-1个元素。取第i-1个元素可能意味着一个从i-1开始需要有一个很大的skip，但是我们却是根据第i个元素的skip来更新dp[i+skip+1]，这是不合理的。
