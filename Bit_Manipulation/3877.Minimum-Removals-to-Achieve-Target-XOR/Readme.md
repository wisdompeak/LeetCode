### 3877.Minimum-Removals-to-Achieve-Target-XOR

#### 解法1

本题要求在nums数组里找一个最长的子序列，使得其XOR Sum等于need^target。

任意子序列的个数是2^n。考虑到n=40，穷举的话是不可行的。但是如果n=20的话，穷举的数目恰好是2^20属于1e6数量级。这就提示我们可以用两遍穷举，然后meet in the middle的策略。

我们将nums分为前后两个部分。对于每一半，我们各自穷举所有的mask，计算出对应XOR Sum数值和其mask的长度，装入一个Hash表。Hash表里永远更新为最长的长度。最后我们枚举前一个Map里的[key1,val1]，然后在后一个Map里寻找对应的`key2=target^key1`，那么`val1+val2`就是一个可能的答案。

#### 解法2

考虑到nums的数值不超过1e4，那么所有XOR Sum的种类也不会超过1e4. 我们可以用常规的DP。令dp[i][v]表示对于前缀nums[1:i]，Xor Sum等于v时的最长子序列长度。状态转移的依据就是当前元素的“选或不选”两种决策：
```
dp[i][v] <= dp[i-1][v^nums[i]]+1
dp[i][v] <= dp[i-1][v]
```
最终返回dp[n][target].
