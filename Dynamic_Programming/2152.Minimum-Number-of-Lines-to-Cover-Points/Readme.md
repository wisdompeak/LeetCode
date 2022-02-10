### 2152.Minimum-Number-of-Lines-to-Cover-Points

从本题的数据规模n<=10来看，用bit mask暴力穷举是正解。我们用一个二进制数state来表示一组点的集合，dp[state]表示这些点最少能用多少条直线覆盖。

如果state的所有点都在一条直线上，那么必然是```dp[state]=1```. 否则的话，这个点集的最优解是需要两条或者更多的直线来覆盖，我们必然可以将这些直线和对应的点归并出两组。这意味着必然有一种方法可以将state分为A子集和B子集，使得```dp[state]=dp[A]+dp[B]```，所以我们只需要枚举state的子集subset，那么```dp[state] = min{dp[subste] + dp[state-subset]}```.

所以本题的解法是：从小到大遍历所有的状态state，对于每个状态dp[state]，考察它的子集subset和补集（注意dp[subset]必然已经是已知的）。dp[state]要么是1，要么就是两个子集状态之和（取最小值）。
