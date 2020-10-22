### 1626. Best Team With No Conflicts

将所有的队员按照年纪排序之后，我们很容易发现，所选的队员需要按照能力值呈现一个递增的序列。这就和longest increasing subsequence非常相似。只不过我们的objective不是长度，而是sum。

状态转移方程如下：
```
dp[i] = max{dp[j]+score[i]} for all j s.t. age[j]<=age[i]
```
