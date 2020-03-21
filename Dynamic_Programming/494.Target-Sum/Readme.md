### 494.Target-Sum

此题用DFS最为直观，但是容易超时，所以记忆化是必须的。除此之外，仍有剪枝的空间。比如当前剩余的数字之和仍小于target的绝对值，那么就可以提前终止。

此题还有一个比较巧妙的解法是DP。这主要得益于题目给出的维度不大，所有元素的SUM小于1000，元素总数N小于20.于是我们可以开辟DP数组```DP[i][s]```，表示前i个数可以通过加减运算得到s的个数。那么显然就有动态转移方程：
```
for i = 0 to N-1
   for s = -SUM to SUM
   {
      dp[i][s]+=dp[i-1][s-nums[i]]
      dp[i][s]+=dp[i-1][s+nums[i]]
   }
```
唯一需要考虑的问题是，s可能是负数，而s作为数组的index不能为负。解决方法就是给s加上一个SUM的偏移，将```[-SUM,SUM]```的区间平移至```[0,SUM*2]```作为DP数组的第二个维度的index


[Leetcode Link](https://leetcode.com/problems/target-sum)