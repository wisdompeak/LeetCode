### 152.Maximum-Product-Subarray

此题是053.Maximum-Subarray的进阶版。本题的关键点在于，如果nums[i]是负数，那么求以i为结尾的最大乘积子数组，其实转化为求以i-1为结尾的最小乘积子数组。所以我们每次考察以i为结尾的子数组时，需要同时保留最大和最小值。于是状态转移方程：
```cpp
            curMax = max(max(preMin*nums[i],preMax*nums[i]),nums[i]);
            curMin = min(min(preMin*nums[i],preMax*nums[i]),nums[i]);            
```
最后返回的结果不是最后的curMax,而是遍历每个回合的curMax中的最大值。


[Leetcode Link](https://leetcode.com/problems/maximum-product-subarray)
