### 935.Knight-Dialer

这是一道简单但是比较有趣的题目。DP的方法还是比较容易想到的。令dp[k]表示当前拨号数字为ｋ的方案数，显然它取决于在按ｋ之前的那个数字的拨号方案数之和。

举个例子，第i次拨号时的dp[4]就等于第i-1次拨号时的```dp[0]+dp[3]+dp[9]```，这是因为在盘面上骑士只能从０，３，９这三个位置跳跃到４．


[Leetcode Link](https://leetcode.com/problems/knight-dialer)