### 1631.Path-With-Minimum-Effort

此题的道路可以上下左右行走，显然不是动态规划。用DFS搜索路径的话也是一个天文数字。所以此题必有巧解。

#### 解法1：二分搜索
假设minimum effort是a，那么意味着路径上不能有超过diff大于a的边。怎么验证有没有呢？BFS走一遍就行。从左上角向外扩展，遇到diff大于a的边就绕行，看看最终能否到达右下角。成功的话，就尝试减小a；不成功的话，就尝试增大a。这个时间复杂度是```o(M*N*logH)```，H是矩阵元素的最大值。

#### 解法2：Union Find
我们将所有的边按照diff从小到大排个序。优先选最小的边，看能联通哪些点；再选次小的边，看能联通哪些点。直至选中某条边之后，发现起点和终点恰好联通，那么这条边的diff就是答案。

注：此题和[1102](https://github.com/wisdompeak/LeetCode/tree/master/Binary_Search/1102.Path-With-Maximum-Minimum-Value)非常相似。
