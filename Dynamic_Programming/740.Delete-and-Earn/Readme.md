### 740.Delete-and-Earn

#### 解法1：

本题有一个特点，如果我们选择了数值k，那么所有值为k的元素都会被计入gain而不能再被访问。这就提示了我们其实不应该按照元素的index顺序遍历（否则可能会遇到很多次已经被处理过的数值），更方便的做法是应该按照元素的value顺序（比如说从小到大）来遍历。

假设我们处理完当前数值k，记目前位置的最大收益是dp[k]。注意这个dp[k]不能保证k被earn与否。可能k这个数被delete and earn了，那么意味着实际的收益应该是dp[k-2]+k;也有可能这个k并没有被delete and earn,那么它的收益完全就取决于dp[k-1]。最终我们会在这两个决策中挑更大的作为dp[k]。

于是动态转移方程就是
```cpp
dp[k] = max(dp[k-2]+gain[k], dp[k-1])
```
其中gain[k]表示对k这个数值进行delete and earn的收益，其中包括了数组中出现重复的k的情况。如果数组中没有k，那么显然gain[k]=0.

应为我们是按照数值的从小到大顺序遍历的，所以最终答案应该是dp[数组最大的value]。

#### 解法2：

此题也可以和198.House Robber做类比。如果你能看出来它的本质是“不能选取任何相邻的两个数”，那么可以用dual status的DP方法：用ｐ表示抢劫此家的价值，用ｑ表示不抢劫此家的价值．那么我们可以用上一家的(p,q)来更新下一家的(p',q')：
```cpp
p'= q + gain[k];
q'= max(p,q);
```


[Leetcode Link](https://leetcode.com/problems/delete-and-earn)