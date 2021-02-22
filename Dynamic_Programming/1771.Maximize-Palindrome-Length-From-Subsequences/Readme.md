### 1771.Maximize-Palindrome-Length-From-Subsequences

本题的突破口是：A的子序列s与B的子序列t拼接起来是回文串，那么意味着t的逆序（记做t'）肯定能与s的某段前缀相同。
```
A: xxx a x b x c xxx
B: xxx c x b x a xxx
B':xxx a x b x c xxx
```
我们希望整体的回文串越长，那么自然希望B的逆序里（记做B'）能与A中的子序列匹配的字符越多越好。也就是说，我们需要求A和B'的最长公共子序列（LCS）。

那么答案就是这个LCS长度的两倍吗？并不是。LCS只是描述了A和B中能够组成的最长的相互对称序列。但是如果A的后半段，或者B的前半段（即B'的后半段），存在自相关的对称序列的话，也是可以贡献在答案里的，例如：
```
A: x x x a x b x c [x d e d]
B: [x x x] c x b x a x x x x
B':x x x a x b x c [x x x x]
```
所以当我们已知dp[i][j]表示A的前i个元素、B'的前j个元素能够组成的LCS时，还要查看A[i+1:m]存在的最长回文串长度、或者B[j+1:n]存在的最长回文串长度。两者取更大的那个，结合之前的互相对称的LCS，才是最后的答案。
