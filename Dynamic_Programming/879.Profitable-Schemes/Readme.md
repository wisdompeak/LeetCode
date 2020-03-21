### 879.Profitable-Schemes

非常常规的DP题。设计状态变量dp[person][profit]表示：恰好用person个人力、并恰好达到profit的利润的方案数。我们遍历所有的project，根据这个project来更新dp状态。基本的状态转移方程是：对于一个project (x,y)，我们有```dp[person+x][profit+y] += dp[person][profit]```。

需要注意的技巧。我们不需要对于利润大于P的dp开辟更多空间，即dp的第二个维度开到P就可以了。这是因为对于利润是P,P+1...P+M的情况，对于我们都没有区别（我们只在乎他们的总和），并且以后我们不会用这些状态给别的状态赋值。所以，我们把利润大于P的状态，都会累加进状态dp[person][P]里面去。

因此最后的结果应该是 ```sum{dp[i][P]} over i=1,2,...,G```，其中P特殊地用来表示P及P以上的利润。


[Leetcode Link](https://leetcode.com/problems/profitable-schemes)