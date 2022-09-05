### 2400.Number-of-Ways-to-Reach-a-Position-After-Exactly-k-Steps

#### 解法1：常规DP
本题常规的解法是DP。我们令dp[t][p]表示第t步的时候移动到p的位置有多少种方案。显然我们有```dp[t][p] = dp[t-1][p-1] + dp[t1][p+1]```.

这里我们需要注意的是startPos和endPos的绝对位置对于我们没有用处，我们只关心最终的相对移动，即`|endPos-startPos|`.我们在计算dp的循环里，p的范围应该是[-k,k].

#### 解法2：组合数
我们令`d=|endPos-startPos|`，那么我们知道，为了通过k步的移动、最终偏移d的位置，需要前进a步且后退b步，且`a+b=k`，其中a就是`(d+k)/2`，其中`d+k`必须能被2整除。这样的话，本题就是求在k步移动里如何安排其中的a步前进。顾方案数就是comb(k,a)。我们可以利用组合数的递推公式`comb[i][j] = comb[i - 1][j - 1] + comb[i - 1][j]`求解。
