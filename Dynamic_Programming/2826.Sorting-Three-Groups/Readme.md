### 2826.Sorting-Three-Groups

令dp[i][j]表示截止到第i个元素为止构成j个group的最小代价，其中j=1,2,3. 显然有
```
dp[i][1] = dp[i-1][1] + (nums[i]!=1);
dp[i][2] = min(dp[i-1][1], dp[i-1][2]) + (nums[i]!=2);
dp[i][3] = min(min(dp[i-1][1], dp[i-1][2]), dp[i-1][3]) + (nums[i]!=3);
```
最终返回dp[n][1],dp[n][2],dp[n][3]中的最小值。
