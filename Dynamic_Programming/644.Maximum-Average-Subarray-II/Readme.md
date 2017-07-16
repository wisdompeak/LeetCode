### 644.Maximum-Average-Subarray-II

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
 for (int j=i-dp[i-1]; j<=i-k+1; j++)
 {
    考察 nums[j]~nums[i]这个subarray的平均值，更新全局最大。
 }
得到最优的 dp[i]
```
