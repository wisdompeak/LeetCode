### 3077.Maximum-Strength-of-K-Disjoint-Subarrays

我们令dp[i][j]表示前i个元素里找出j个subarray的最优解。注意，我们认为k是个常数，即`dp[i][j] = sum[1]*k - sum[2]*(k-1) + ...`，而不是`dp[i][j] = sum[1]*j - sum[2]*(j-1) + ...`.

显然，我们在考虑dp[i][j]时，会思考对于nums[i]的决策。如果nums[i]不加入任何subarray，那么就有`dp[i][j] = dp[i-1][j]`. 如果nums[i]加入subarray，那么它就是属于sum[j]。但是此时有一个问题，它是加入已有的sum[j]呢，还是自己独创一个sum[j]。前者的话就是`dp[i-1][j]+nums[i]`，后者就是`dp[i-1][j-1]+nums[i]`. 但是注意到，前者要求`dp[i-1][j]`中的sum[j]必须结尾在第i-1个元素，才能将nums[i]顺利接在sum[j]里，而我们的dp定义并没有这个约束。

为了解决这个问题，我们重新定义dp，加入第三个维度表示“最后一个subarray是否以当前元素结尾”。即dp[i][j][0]表示前i个元素分成j个subarray，且nums[i]不参与最后一个subarray；类似dp[i][j][1]表示前i个元素分成j个subarray，且nums[i]参与了最后一个subarray。于是我们容易写出新的转移方程。以j是偶数为例，对于dp[i][j][0]，由于nums[i]不起作用，完全取决于dp[i-1][j]，不用考虑它的第三个维度：
```
dp[i][j][0] = max(dp[i-1][j][0], dp[i-1][j][1]);
```
对于dp[i][j][1]，我们需要考虑nums[i]是否是接在nums[i-1]后面属于同一个subarray，还是自己新成立一个subarray。如果是前者，我们考虑的前驱状态是dp[i-1][j][1]; 如果是后者，我们考虑的前驱状态是dp[i-1][j-1][x]
```
dp[i][j][1] = max(dp[i-1][j][1], max(dp[i-1][j-1][0], dp[i-1][j-1][1])) - (LL)nums[i]*(k+1-j);   
```
最终返回的答案是`max(dp[n][k][0], dp[n][k][1])`.

初始状态是对于所有的dp[i][0][0]赋值为零，其他都设为负无穷大。

