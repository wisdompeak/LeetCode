### 139.Word-Break

此题只要能想到用DP来做,就是成功的关键.

本题和```322.Coin Change```很相似.要使得dp[i]能够成功,必然是需要找到一个小于i的序号j,使得s[j:i]恰是一个单词,并且dp[j-1]也能成功.所以遍历一下j即可.于是动态转移方程就写出来了,时间复杂度是o(n^2).

初始条件需要稍微注意一下.此题里,改成1-index更加方便,这样初始条件就是dp[0]需要设置为True即可.

补充：相比于在内层循环中遍历j的位置，有一种更高效的方法。就是在内存循环中遍历wordDict，查看是否有任何一个单词word能够匹配s[0:i]的后缀。这种解法在s很长而wordDict很小的情况下，优势非常明显。


[Leetcode Link](https://leetcode.com/problems/word-break)