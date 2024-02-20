### 3018.Maximum-Number-of-Removal-Queries-That-Can-Be-Processed-I

我们令dp[i][j]表示将nums砍至区间[i:j]时，能够通过多少个queries。显然，dp[i][j]是可以由dp[i-1][j]或dp[i][j+1]转化来的。例如，令`dp[i-1][j]=t`，说明操作至[i-1:j]时已经通过了t个queries，那么如果`nums[i-1]>=queries[t]`的话，就可以再砍去nums[i-1]使得通过`t+1`个queries. 反之如果`nums[i-1]<queries[t]`的话，那么nums[i-1]只能通过预先删除的方法，才能将nums范围收窄至[i:j]，即`dp[i][j] = dp[i-1][j]`.

同理，我们也可以写出dp[i][j]由dp[i][j+1]转化来的方程。

这是所有第二类区间型DP中，少数需要先求大区间、再求小区间的题。

本题的初始状态就是`dp[0][n-1] = 0`，即未做任何操作前，通过的queries的个数是0.

最终我们求所有dp[i][j]中的最大值。但特别需要注意的是，我们只能求得最小长度为1的区间，即dp[i][i]，它表示删除到仅剩一个元素nums[i]时通过的queries个数（假设是t）。而然，此时还可以继续删除：只要`nums[i]>=queries[t]`，那么意味着nums可以全部被删除（即通过t+1个queries）。在更新最终答案时需要额外处理这种情况。

