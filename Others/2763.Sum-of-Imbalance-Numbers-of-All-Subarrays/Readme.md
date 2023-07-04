### 2763.Sum-of-Imbalance-Numbers-of-All-Subarrays

#### 解法1：
因为数据规模不大，可以用n^2的复杂度，那么我们可以暴力模拟每个subarray。当我们固定i为左边界的时候，逐个向右移动j作为右边界，考察此时[i:j]的subarray里有多少个符合条件的index。

假设在[i:j-1]的旧subarray里已经有count个符合条件的index，当我们需要考察nums[j]加入后的新subarray时，计数会有什么变化呢？我们发现，新subarray基本上可以继承旧subarray的count，但是我们需要考虑nums[j]带来的变化。

1. 通常情况下，如果旧subarray里面的元素分布是稀疏的，那么一个新元素nums[j]的引入大概率会贡献一个合法的index（旧subarray为空除外），即`count+=1`。除非旧subarray里面已经有了`nums[j]`这个元素，那么显然，相同数值的元素不能贡献多于一个的合法index，我们会忽略count的变化跳出剩余的判断。
2. 如果发现旧subarray里面已经有了`nums[j]+1`这个元素，那么nums[j]会因为它的缘故无法被认为是合法的index，故取消刚才的计数`count-=1`.
3. 如果发现旧subarray里面已经有了`nums[j]-1`这个元素，那么nums[j]反而会侵蚀掉一个之前认为是合法的index，故扣减计数`count-=1`.

综上，此时的count就是[i:j]对应的新subarray的合法index的计数。
