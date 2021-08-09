### 1959.minimum-total-space-wasted-with-k-resizing-operations

我们令dp[i][j]表示前i个数经过j次调整后的最小浪费空间。

我们在计算dp[i][j]的时候，考虑的是最后一次调整所覆盖的范围。我们遍历一个分割位置s，假设[s:i]这个区间是最后一次调整的范围，那么状态转移方程式
```cpp
dp[i][j] = min{ dp[s-1][j-1] + cost[s:i] } for s=1,2,...,i
```
那么我们怎么知道最后一次调整应该调整到什么size呢？其实很简单，要使最后一次调整的size能够装下nums[s:i]的所有元素，并且浪费空间最少，那么必然size就是nums[s:i]中的最大值mx。这样最后一个区间的浪费空间就是```mx*(i-s+1) - intervalSum[s:i]```.

在实际的操作中，我们会将s从大到小遍历，这样mx和intervalSum都可以o(1)时间更新。

总的时间复杂度是o(NKK).
