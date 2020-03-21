### 1269.Number-of-Ways-to-Stay-in-the-Same-Place-After-Some-Steps

不要想什么卡特兰数，不要误入歧途。就是非常简单的动态转移方程：
```
dp[i][j] = dp[i-1][j]+dp[i-1][j-1]+dp[i-1][j+1]
```
其中dp[i][j]就表示第i步能达到第j个位置的方案数。


[Leetcode Link](https://leetcode.com/problems/number-of-ways-to-stay-in-the-same-place-after-some-steps)