### 410.Split-Array-Largest-Sum

#### 解法1: DP  
大多数的数组问题都可以用动态规划解决。 

设计dp[i][k]表示元素1~i分成k份的最佳方案，即最大子区段的最小可能值。  

如何设计转移方程呢？无非就是考虑dp[i][k]和这些前态的关系：dp[i-？][k], dp[i][k-？]。  
可以发现，dp[i][k]和dp[i-1][k-1]有直接关系。遍历所有将前j个元素（j最小就是k-1）分成k-1份的方案，加上最后一份（就是 sum[i]-sum[j]）的影响。 

所以转移方程是： dp[i][k]=min{j} ( max(dp[j][k-1],sum[i]-sum[j]) )

注意的细节是，sum[i]的计算可能会溢出。sum[i]-sum[j]可以转化为 dp[i][1]-dp[j][1].

#### 解法2: Binary Search
进行k的二分搜索，k就是代表nums分成m份后最大自区段的和。
分析：k的最小值是nums里的最大值；k的最大值是数组元素的总和；对于任一个mid，另写函数用贪心法判断是否满足要求。满足要求的话，就继续缩小k来尝试。

如何判断k是否可行呢？两个判据：
1. 如果任何nums[i]>k，则不可行。
2. 尽可能地合并元素，使得任何子区段的和都不超过k，并在遍历的过程中记录这些子区段的数目，超过m的话就说明不可行。

此题和 ```1011. Capacity To Ship Packages Within D Days``` 几乎一模一样。


[Leetcode Link](https://leetcode.com/problems/split-array-largest-sum)