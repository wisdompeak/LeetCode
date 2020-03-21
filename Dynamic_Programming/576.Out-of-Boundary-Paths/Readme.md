### 576.Out-of-Boundary-Paths

本题最简洁的解法是考虑从边界到出发点的逆向移动。令边界上的格子的初始值为1（起点），考虑经过N步之后，到达(i,j)的方案有多少。在不考虑边界情况下，容易知道
```
dp[i,j,k] = dp[i-1,j,k-1] +  dp[i+1,j,k-1] + dp[i,j-1,k-1] + dp[i,j+1,k-1];
```
需要注意的是，对于那些处在边界的格子，必须在每一步都赋值为1，即源源不断地要作为起始点。
```
dp[i,j,k] = 1;
```
输出结果就是dp[i0,j0,N]。当然，不必开那么多二维数组，只要两个就行了。


[Leetcode Link](https://leetcode.com/problems/out-of-boundary-paths)