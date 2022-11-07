### 2361.Minimum-Costs-Using-the-Train-Line

很明显，状态变量dp[i][0]表示到达第i个车站的regular所需要的最小代价，dp[i][1]表示到达第i个车站的express所需要的最小代价。于是有转移方程：
```cpp
dp[i][0] = min(dp[i-1][0] + regular[i], dp[i-1][1] + regular[i]);
dp[i][1] = min(dp[i-1][1] + express[i], dp[i-1][0] + expressCost + express[i]);
```
注意我们不需要考虑dp[i][0]与dp[i][1]之间的转移。这是因为，我们如果想要从dp[i][0]转移到dp[i][1]，其目的一定只是为了后续得到dp[i+1][1]。单独从第i站的角度来看，只要到了regular或express都算达成了任务，两者间的跳转对于第i站而言没有意义。
