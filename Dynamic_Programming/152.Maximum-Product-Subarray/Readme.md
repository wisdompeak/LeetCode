### 152.Maximum-Product-Subarray

此题的巧思妙解在于，由于乘法的正负性不确定，所以我们每次保留当前的最大最小值。那么就有状态转移方程：
```cpp
            curMax = max(max(preMin*nums[i],preMax*nums[i]),nums[i]);
            curMin = min(min(preMin*nums[i],preMax*nums[i]),nums[i]);            
```
特别需要注意的是，返回的结果不是最后的curMax,而是遍历每个回合的curMax中的最大值。
