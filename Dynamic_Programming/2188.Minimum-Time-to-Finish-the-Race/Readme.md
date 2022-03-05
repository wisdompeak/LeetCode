### 2188.Minimum-Time-to-Finish-the-Race

整体思想显然是DP。令dp[i]表示跑i圈的最小代价，那么它取决于最后一次换胎的选择。假设最后一次换胎跑了j圈，那么就有```dp[i] = dp[i-j] + changTime + minTime[j]```，其中j表示minTime[j]是在所有轮胎类型中跑j圈最快的时间。所以求解DP的过程大致是o(numLaps^2) = 1e6 的复杂度，可以接受。

那么预处理minTime需要多少时间呢？在有m种轮胎，如果把所有的minTime[t], t=1,2,3,...numLaps的情况下，我们需要花```o(m*numLaps)```的时间，那就是1e8数量级，必然TLE。该如何改进呢？

