### 053.Maximum-Subarray

本题是一道经典题，其算法类似动态规划，称之为Kadane算法。

我们考虑每个以i截止的maximum subarray是什么？显然对于i而言，它只有两种选择：
1. 这样的subarray里面，i是接在元素i-1后面。为了使得subarray最大，自然问题就转化为希望得到以i-1结尾的maximum subarray。
2. 这样的subarray里面，i不是接在前一个元素之后。这就意味着自己是这个maximum subarray中的唯一一个元素。

所以，我们定义dp[i]表示以元素i结尾的maximum subarray的和。那么dp[i]就是上面两种方案中取较大的值。因为我们并不知道全局最大的subarray的截止点在哪里，所以最终的答案就是所有dp[i]中的最大值。
