### 1473.Paint-House-III

#### 解法1：
令dp[i][j][k]表示前i个房子构成了j个block，并且第i个房子喷涂的颜色是k的最小代价。分两种情况讨论：

1. 当```house[i]!=0```，说明第i个房子无法更改颜色，此时dp[i][j][k]取决于前面一个房子的颜色kk。遍历kk的可能。如果kk与k相同，那么第i个房子和前面的房子可以合并为一个block，即```dp[i][j][k] = min{self, dp[i-1][j][kk]}```。如果kk与k不同，那么第i个房子就是第j个block的第一个，即```dp[i][j][k] = min{self, dp[i-1][j-1][kk]}```。

2. 当```house[i]==0```，说明第i个房子可以任意喷涂k=1,2,..,n，记得加上喷涂成本. 同理，遍历前一个房子的颜色kk。如果kk与k相同，那么第i个房子和前面的房子可以合并为一个block，即```dp[i][j][k] = min{self, dp[i-1][j][kk]+cost[i][k]}```。如果kk与k不同，那么第i个房子就是第j个block的第一个，即```dp[i][j][k] = min{self, dp[i-1][j-1][kk]+cost[i][k]}```。

初始状态较为容易的写法是对第1座房子做单独分析。如果第一座房子已经喷涂，那么`dp[1][1][houses[1]] = 0`，否则`dp[1][1][k] = cost[1][k]`.其余的状态都设为无穷大。DP的转移从i=2开始。

最终的答案是在所有房子喷涂完、构造了target个block、最后一个房子颜色任意的前提下，取最小值。即```min{dp[m][target][k]，for k=1,2,..,n```

#### 解法2：
上述的解法中，第二情况下会有四层循环，分别遍历i,j,k,kk，时间复杂度达到了```o(m*m*n*n)```. 事实上可以优化到```o(m*m*n)```。

我们考察解法1的写法：
```cpp
for (int j=1; j<=target; j++)
    for (int k=1; k<=n; k++)
    {
        for (int kk=1; kk<=n; kk++)
        {
            if (kk==k)
                dp[i][j][k] = min(dp[i][j][k], dp[i-1][j][kk] + cost[i][k-1]);
            else
                dp[i][j][k] = min(dp[i][j][k], dp[i-1][j-1][kk] + cost[i][k-1]);
        }
    }    
```
我们看到对于每个k，我们都要把kk都遍历一遍找dp[i-1][j-1][kk]的最小值。事实上这个最小值可以对大部分的k共享。我们可以提前把dp[i-1][j-1][kk]的最小值计算出来，假设对应的是minCost和kk1。对于大部分的dp[i][j][k]，可以通过这个minCost（即第i-1个房子、构造j-1个block、用第kk1种颜色）转移过来。但是注意，如果最小值对应的kk1恰好就是k，那么dp[i][j][k]只能从dp[i-1][j-1][kk]里的第二小的值转移。
```cpp
for (int j=1; j<=target; j++)
{
    vector<pair<int,int>>temp;
    for (int kk=1; kk<=n; kk++)
    {
        temp.push_back({dp[i-1][j-1][kk], kk});
    }
    sort(temp.begin(), temp.end()); // save the min dp[i][j-1][kk] and the second min

    for (int k=1; k<=n; k++)
    {
        dp[i][j][k] = dp[i-1][j][k] + cost[i][k-1];
        if (k!=temp[0].second)
            dp[i][j][k] = min(dp[i][j][k], temp[0].first + cost[i][k-1]);
        else
            dp[i][j][k] = min(dp[i][j][k], temp[1].first + cost[i][k-1]);
    }                    
}
```                
这样的写法的循环只有三层，分别是i,j, kk（与k并列）.
