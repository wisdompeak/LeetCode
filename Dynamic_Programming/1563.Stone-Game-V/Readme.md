### 1563.Stone-Game-V

本题是典型的区间型的DP。令dp[i][j]表示对于区间[i,j]，如果让对手先行，我方能够得到的最大得分。注意，对手做的决策是由我方提出的，所以我方会做尽量有利于自己的决策。当然，为了知道哪个是最有利的决策，我们需要遍历所有的决策。每一种决策就是将[i,j]划分为两个区间[i,k],[k+1,j]，然后我们就知道左子区间与右子区间的和，根据规则，我们对我方的得分有如下的递归定义：
```cpp
if (leftSum<rightSum)
    dp[i][j] = max(dp[i][j], dp[i][k]+leftSum);
else if (leftSum==rightSum)
    dp[i][j] = max(dp[i][j], max(dp[i][k],dp[k+1][j])+rightSum);
else if (leftSum>rightSum)                    
    dp[i][j] = max(dp[i][j], dp[k+1][j]+rightSum);     
```
dp[i][j]的最终值，就是所有划分区间的可能决策里（即遍历k的位置）的最大值。

dp的边界值是当区间长度为2的时候，我方的得分只能是较小的那个元素。

因为LC平台对CPP的编译优化设置很低，本题的DP解法用cpp实现会超时。一个绕行的方法是改写成递归+记忆化的形式：
```cpp
if (leftSum<rightSum)
    dp[i][j] = max(dp[i][j], solve(i,k)+leftSum);
else if (leftSum==rightSum)
    dp[i][j] = max(dp[i][j], max(solve(i,k),solve(k+1,j))+rightSum);
else if (leftSum>rightSum)                    
    dp[i][j] = max(dp[i][j], solve(k+1,j)+rightSum);            
```
这种方法能AC的原因在于，当```leftSum<rightSum```的时候，只需要向下递归solve(i,k)而不需要向下递归solve(k+1,j)，可以省略一些分支。而bottom-up的DP写法，则需要计算出任意两点区间的dp值。
