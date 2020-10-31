### 1638.Count-Substrings-That-Differ-by-One-Character

最初的感觉可能是一道双序列型的DP。所以我首先写出的是状态变量dp[i][j]，表示字符串s的前i个、字符串t的前j个能有多少种答案。接下来我就会考虑如何从s[i]和t[j]下手：怎么样能使得s[i]和t[j]是符合要求的substring的一部分？

我发现，当s[i]!=t[j]的时候，我们不得不计算s[i]和t[j]之前有多少个连续的、相等的字符的个数a。这个时候灵光一现，如果我们也计算出s[i]和t[j]之后有多少个连续的、相等的字符的个数b，那么我们其实就解决了一类符合题意的substring的pattern：那就是以s[i]和t[j]做为“Differ by One Character”的位置，那么这样的字符串其实就是有```(a+1)*(b+1)```个。事实上，所有的符合条件的substring都可以归为若干类，每一类都有着相同的“Differ by One Character”的位置(i,j).

所以至此，本题的思路就有了。我们遍历所有的配对(i,j)，如何s[i]!=t[j]，那么我们就计算相应的a和b（定义见前），然后```ret+=(a+1)*(b+1)```.至于a和b，显然我们提前计算出来。令dp1[i][j]表示s[i]和t[j]之前的最长的相同substring（包括s[i]和t[j]本身）；令dp2[i][j]表示s[i]和t[j]之后的最长的相同substring（包括s[i]和t[j]本身）。这两个量都很容易用动态规划来解决。
