### 3669.Balanced-K-Factor-Decomposition

用sqrt(n)的时间将n的所有divisors求出来。本题转化为在divisors数组中寻找k个元素使得乘积恰好为n。因为k的个数较小，可以用暴力DFS解决。

递归函数`dfs(i,n,k)`表示要将n拆分为k个元素的乘积，当前可以从第i个divisor开始选择。选中某个约数d（编号为j）之后，即可递归处理`dfs(j,n/d,k-1)`.当k=1时，即可记录所选中的约数。
