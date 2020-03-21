### 487.Max Consecutive Ones II  

类似于动态规划的思想，设计两个状态变量： count1记录当前从未使用反转权力、可以得到的连续1的个数；count2记录当前已经使用反转权力、可以得到的连续1的个数。

如果nums[i]==1，那么count1和count2各自加1，没有问题。

如果nums[i]==0，那么count1要置零；count2怎么办呢？事实上count2=count1+1既可。

一路上追踪最大曾出现过的count2就是最后的答案。


[Leetcode Link](https://leetcode.com/problems/max-consecutive-ones-ii)