### 891.Sum-of-Subsequence-Widths

对于任何A中的一个子序列，其实相当于在A中任取若干个数组成combination。所以总共有2^n种子序列。既然是组合，那么顺序其实无所谓。我们可以先将A排序一下。

将A排序之后，我们立即可以发现，我们可以遍历任意的A[i]和A[j]做为最小值和最大值，那么这样的子序列马上就能知道有```2^(j-i-1)```种，因此可以用o(n^2)的时间复杂度来解决：```sum += (A[j]-A[i])*pow(2,j-i-1)```

还有更优化的方法。求所有子序列的max-min的和，等价于求所有子序列的max的和，减去所有子序列的min的和。这样的话我们只需要遍历任意的A[i]：当它作为最小值时的子序列有2^(n-i-1)种；当它作为最大值时的子序列有2^i种。所以代码很简单，只要o(n)的复杂度：
```cpp
for (int i=0; i<n; i++)
{
  sum += A[i]*pow(2,i);
  sum -= A[i]*pow(2,n-1-i);
}
```


[Leetcode Link](https://leetcode.com/problems/sum-of-subsequence-widths)