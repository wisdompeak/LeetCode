### leetcode-221-Maximal-Square  
##### 解法1：brutal search
首先预处理得到矩阵sum[i][j]，表示从左上角(0,0)到(i,j)处的所有元素之和。注意技巧，sum在定义时两个维度大小都增1。

对于每一个sum[i][j]，判断是否存在以(i,j)为右下角、边长为k的正方形，k的取值从1到不越界。判断表达式是：
```cpp
if (sum[i][j]-sum[i-1][j]-sum[i][j-1]+sum[i-1][j-1] == k*k) 
```
73ms

##### 解法2：逐行判断，贪心法
完全类似于 leetcode 85 maximal rectangular，变换成在一维上求最大正方形。

核心思想：不断加入数组元素，维护一个非减的栈序列，注意栈元素是数组的index而不是数值本身。遇到下一个数组元素比栈顶元素小的时候，退栈，判断该栈顶元素能够围成的最大正方形空间。
```cpp
if （height[i]>=height[s.top()])  
  {push(i); continue;}
else    
  { int H=height[s.top()];
    s.pop();
    result = max(result,min(H,i-s.top()-1);
  }  
```
9ms

##### 解法3：动态规划  
设计dp[i][j]表示右下角为(i,j)的最大正方形边长。则有动态转移方程： 
```cpp
if (matrix[i][j]==1)
  dp[i][j]=min(dp[i-1][j],dp[i][j-1],dp[i-1][j-1])+1
else
  dp[i][j]=0;
```
可以这么理解上述的动态转移方程。假设matrix[i][j]==1，那么对于右下角为（i,j）的可能的最大正方形，主要取决于dp[i-1][j-1]有多大，其次还要考虑第i行和第j列分别有多少1与（i,j）连着。所以，这个最大正方形，其下边长由min(dp[i-1][j-1],dp[i][j-1])决定，有边长由min(dp[i-1][j-1],dp[i-1][j])决定。

最后注意，输出的面积应该是最长边长的平方。


[Leetcode Link](https://leetcode.com/problems/maximal-square)