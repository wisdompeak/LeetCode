### 664.Strange-Printer

设计动态转移方程dp[i][j]，表示打印以s[i]开始、s[j]结尾的子串，需要最少的turns。

最简单的递推关系是：dp[i][j]=dp[i][j-1]+1.但这不见得是最优的。寻找最优方案的递推是什么呢？
```cpp
dp[i][j] = min { dp[i][k]+dp[k+1][j-1] }  for s[k]==s[j]
```
也就是试图把dp[i][j]拆分两部分，如果s[k]==s[j]，那么在构造第一部分的时候，可以让打印机在打印s[k]时顺带继续打印到j的位置，接下来的就交给第二部分dp[k+1][j-1]去构造。注意，如果k+1>j-1，那么dp值默认为0.

所以比较粗糙的动态转移代码如下：
```cpp
for (int i=0; i<n; i++)
 for (int j=i; j<n; j++)
 {
    dp[i][j]=dp[i][j-1]+1;
    for (int k=i; k<i+len-1; k++)
    {
       if (s[k]==s[j])
          dp[i][j]=min(dp[i][j], dp[i][k]+dp[k+1][j-1]);
    }    
 }
 return dp[0][n-1];
```
上述的代码问题在于两个大循环。第一步就固定了i=0，然后遍历j的时候，需要已知dp[k+1][j-1]这些尚未赋值的量。怎么修改呢？回顾上述的动态转移方程，是将一个较长的子序列拆分成为两个较短的子序列，所以我们应该先计算出那些较短子序列的dp值，再推出较长子序列的dp值。所以我们应该改用len（子序列的长度）作为最外层的大循环，再用起始点i作为第二层循环。
```cpp
        for (int len=2; len<=n; len++)
         for (int i=0; i<=n-len; i++)
         {
             dp[i][i+len-1]=dp[i][i+len-2]+1;
             for (int k=i; k<i+len-1; k++)
             {
                 if (s[k]==s[i+len-1])
                     dp[i][i+len-1]=min(dp[i][i+len-1], dp[i][k]+dp[k+1][i+len-2]);
             }
         }
        return dp[0][n-1];         
```
初始条件是：
1. dp[i][j]==1 when i==j，即len的长度为1; 
2. dp[i][j]==0 when i>j; C语言里如果用int[][]来定义二维数组的话，元素默认值都是0.
