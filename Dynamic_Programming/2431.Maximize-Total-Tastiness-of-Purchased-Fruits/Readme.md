### 2431.Maximize-Total-Tastiness-of-Purchased-Fruits

很常规的DP模式。令dp[i][j][k]表示前i个水果、花费j的钱、使用k张半价券，所能得到的最大tastiness。

显然，我们会考虑对第i个水果的决策：
1. 我们不买第i个水果，`dp[i][j][k] = dp[i-1][j][k]`;
2. 我们原价买第i个水果，`dp[i][j][k] = dp[i-1][j-price[i]][k] + tastiness[i]`;
3. 我们半价买第i个水果，`dp[i][j][k] = dp[i-1][j-price[i]/2][k-1] + tastiness[i]`;

注意为了不出现越界，我们使用上述的转移方程时，需要对j和k加上约束。此外`i=0`时单独处理dp最为方便。
