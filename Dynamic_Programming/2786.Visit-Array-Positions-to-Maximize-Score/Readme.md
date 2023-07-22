### 2786.Visit-Array-Positions-to-Maximize-Score

令dp[i][j]表示前i个元素里能够得到的最大值，并且最后一个元素的奇偶性是j。

当第i个元素不取时，dp[i][j] = dp[i-1][j]

当第i个元素取时，查看它的奇偶性，dp[i][j]根据j的奇偶性与nums[i]奇偶性的差异，决定是否减去x的代价。

最终答案是dp[n-1][0]和dp[n-1][1]的较大值。
