### 927.Three-Equal-Parts

本题的突破口就是全局1的个数。首先，整个数组里面1的个数必须要能被3整除。其次，确定了每个part里面1的个数后（记为count），从后往前数count个1，就已经确定了这个数长什么样了（记为X）。

然后我们从数组最前端开始忽略若干个先导零，从第一个出现1的地方开始判断这个subarray是否等于X。如果OK，那么我们再忽略若干个先导零，在从下一个出现1的地方开始判断这个subarray是否等于X。如果再OK，那么three equal parts就已经划分好了。


[Leetcode Link](https://leetcode.com/problems/three-equal-parts)