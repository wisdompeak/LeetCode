### 3196.Maximize-Total-Cost-of-Alternating-Subarrays

本题的本质就是，每个元素可以更改它的符号，但是不能连着两个元素都更改符号。求所有元素和的最大值。这就是house robber。

令dp[i][1]表示第i个元素更改符号时、前i个元素的最大收益；令dp[i][0]表示第i个元素不更改符号时、前i个元素的最大收益。则有转移方程：
```cpp
dp[i][1] = dp[i-1][0] - nums[i];
dp[i][0] = max(dp[i-1][1],dp[i-1][0])+nums[i];
```
最终答案就是查看最后一个元素对应的dp[n-1][0或1]的最大值。
