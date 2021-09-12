### 2002.Maximum-Product-of-the-Length-of-Two-Palindromic-Subsequences

因为只有12个字符，我们可以暴力枚举拆解的方案，也就是2^12=4096种方法，将原字符串拆为两个subsequence。然后查看每个subsequence里面最长的回文子序列。

对于一个subsequence里面的最长回文子序列问题，我们可以将这个子序列收拢转化为一个常规的字符串。求字符串里的最长回文子序列，这是一个经典问题。可以用o(N^2)的DP。
