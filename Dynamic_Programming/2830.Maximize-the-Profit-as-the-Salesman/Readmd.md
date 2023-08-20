### 2830.Maximize-the-Profit-as-the-Salesman

此题和`2008.Maximum-Earnings-From-Taxi`几乎一样。考虑到`the number of houses`只有1e5级别，最简单的方法就是令dp[i]前i个房子所能得到的最大收益。

我们遍历以i结尾的offer，如果该offer的跨度是从[j,i]，价值是v，那么我们就有一种转移的方法`dp[i]=dp[j-1]+val`. 除此之外，如果不考虑任何offer，则有`dp[i]=dp[i-1]`. 我们从中选一个最优解作为dp[i]即可。

如果本题里houses的数目是1e9级别，我们就需要进行离散化的处理，将所有offer的右边界组成数组T，排序后进行遍历。对于跨度是[t1,t2]的offer，我们需要用二分法在T中找到最后一个小于等于t1的下标，再进行dp的转移。
