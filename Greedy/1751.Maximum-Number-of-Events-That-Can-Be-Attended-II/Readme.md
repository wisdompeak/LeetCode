### 1751.Maximum-Number-of-Events-That-Can-Be-Attended-II

本题和```1235.Maximum-Profit-in-Job-Scheduling```非常相似。差别是dp状态多了一个维度来表示可以取多少个区间。

我们首先要将所有events按照endTime排序。令dp[i][j]表示前i个events里面我们取j个events能得到的最大收益。计算dp[i][j]时有两种决策：
1. 我们不选择events[i]，那么dp[i][j]就等于在前i-1个events里面取j个的最大收益，即dp[i][j]=dp[i-1][j]
2. 我们选择events[i]作为第j个选中的项目，那么我们需要考虑第j-1个项目在哪里？显然这个项目的endTime必须必events[i][0]要小。于是我们可以用二分法，在所有endTimes里找到截止时间恰好早于events[i][0]的项目t，于是dp[i][j]就转化为考察在前t个项目里选取j-1个的最大收益，然后再加上events[i][2]本身。

最终的答案就是max(dp[m][x])，其中m是events的总数。注意答案不一定是dp[m][k]，因为强制取k件不重叠的区间，不见得是最大的利润。
