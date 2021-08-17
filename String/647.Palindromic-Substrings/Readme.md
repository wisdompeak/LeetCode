### 647.Palindromic-Substrings

#### 解法1：暴力
遍历 for (i=0; i<n; i++)，考察以i为中心的回文串个数（回文串长度为奇数）、i和i+1为中心的回文串个数（回文串长度为偶数），分别加入总的结果中。

考察方法是以中心i往两边扩散。一旦发现无法实现中心对称，则可以跳过这个i。整体的时间复杂度是 o(n^2)

#### 解法2：Manacher
此题是Manacher的模板题。注意，求出T串的P[i]之后，每一个中心点的最长回文串半径（去除了#字符）其实是```(P[i]+1)/2```

[Leetcode Link](https://leetcode.com/problems/palindromic-substrings)
