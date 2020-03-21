### 322.Coin-Change

基本的动态转移方程很明确 dp[n] = min(dp[n-k1],dp[n-k2], ..., dp[n-ki]) +1，其中k_i表示coins数组中提供的面额.

需要注意的很多细节：
1. 因为dp数组开辟的大小为 vector<int>dp(amount+1,0)，所以初始化的时候，如果 k>amount, 则 dp[k]则不需要考虑。否则越界.
2. 在动态转移方程中，可能会有n<k以及dp[n-k]==-1的情况，要通过判断语句提前预防。此外，这说明dp[n]是有可能无解的，也要及时做好-1的标注。


[Leetcode Link](https://leetcode.com/problems/coin-change)