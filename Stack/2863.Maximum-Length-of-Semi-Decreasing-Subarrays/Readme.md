### 2863.Maximum-Length-of-Semi-Decreasing-Subarrays

此题和 `962.Maximum-Width-Ramp` 一模一样。

#### 解法1
我们维护一个递增的“数组”arr（注意不是单调栈）。对于新元素nums[i]，我们用二分法在arr里找到第一个大于nums[i]的元素nums[j]，于是对于i而言，它的最大跨度就是`i-j+1`.

如果nums[i]大于数组的尾元素，就加入arr。反之，那么我们就再不用考虑i，这是因为它“又小又晚”，不会为后续的元素带来更大的跨度。
