### 644.Maximum-Average-Subarray-II

#### 解法1
首先最基本o(N^2)的思路要搞清楚。设置两层循环，第一层控制subarray的尾元素位置，第二层控制subarray的首元素位置
```cpp
for (int i=k; i<nums.size(); i++)
 for (int j=0; j<=i-k+1; j++)
 {
    考察 nums[j]~nums[i]这个subarray的平均值，更新全局最大。
 }
```

可见第二重循环有点大，把所有大于等于K程度的subarray都遍历了一遍。能否利用之前的信息呢？比如，若知道了nums[i-1]的最优解，对于解nums[i]的最优解有什么帮助呢？这种思想很像是DP了。

我们考虑如果已经找到了nums[i-1]的最优解：即以nums[i-1]为尾元素、长度为len的subarray，是所有这种这种subarray里均值最大的情况。这说明什么？说明处于len长度之前的那些元素是拖后腿的！它们会拉低以nums[i-1]为尾元素的subarray的均值，同样也会拉低以nums[i]为尾元素的subarray的均值。所以说，第二重循环我么不需要从0开始找。根据nums[i-1]最优解对应的subarray队首开始找就行了。
```cpp
for (int i=k; i<nums.size(); i++)
{
  for (int j=i-dp[i-1]; j<=i-k+1; j++)
  {
    考察 nums[j]~nums[i]这个subarray的平均值，更新全局最大。
  }
  dp[i] = ...
}
```

#### 解法2
上述的解法在lintcode中仍然会超时。下面介绍一个非常巧妙的二分搜索法。

显然二分搜索的上限就是nums里的最大值，下限就是nums里的最小值。我们每次通过low和high确定一个mid，查找nums里是否存在一个子数组是的其平均值大于mid。如果有，那么我们就调高下限至mid；如果没有，我们就降低上限至mid

但是我们如何知道是否存在一个子数组，其平均值大于mid呢？如果我们将这个数组整体都减去mid，那么任务就等价于找到一个平均值大于零的子数组，也就是是说，找到一个和为正数的子数组。

如何确认一个数组里有一段子数组的和为正数呢？我们只要遍历一遍前缀和，发现curSum[i]>preMin即说明存在。这里的preMin就是在i之前的最小的前缀和。可见只要o(n)的搜索就可以完成判断。总体的时间长度就是o(NlogK)，其中K是nums最大最小值之差。


[Leetcode Link](https://leetcode.com/problems/maximum-average-subarray-ii)