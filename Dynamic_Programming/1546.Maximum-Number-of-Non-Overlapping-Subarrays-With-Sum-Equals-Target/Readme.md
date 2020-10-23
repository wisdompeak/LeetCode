### 1546.Maximum-Number-of-Non-Overlapping-Subarrays-With-Sum-Equals-Target

本题很容易看出动态规划的暗示。根据套路，我们尝试定义dp[i]表示前i个元素最多能有多少个符合条件的subarray，然后尝试考虑如何对第i个元素进行处理：要么nums[i]不参与任何subarray，那么就是参与某个subarray。

但我们发现，如果第i个元素是某个subarray中间的任意一员，我们其实很难确定最后一个subarray的范围，没有任何头绪。于是突破点是：如果我们考虑第i个元素是某个subarray的最后一个元素，那么我们其实就唯一确定了这个subarray的范围。方法就是找到一个位置j，使得前缀和presum[j] = presum[i]-target. 如果这个条件满足，那么[j+1,i]就是一个符合条件的subarray。接下来就迎刃而解。我们可以用hash表来存下每个presum对应的所有idx，那么
```
dp[i] = max{dp[j]+1} for all j st. sum[j+1,i] = presum[i]-presum[j] = target
```
注意，还有一种情况是元素i不参与任何subarray，那么它也有一个default value就是dp[i-1].

以上的方法是o(N^2)，但还可以改进。事实上我们并不需要在hash表中存下每个presum对应的所有idx，其实只需要存下最靠后的一个idx就可以了。这是因为数字越多，我们可能得到的最优答案肯定只增不减。即如果presum[j1]==presum[j2]且j1<j2，那么一定有贪心的结论```dp[j1]<=dp[j2]```。
