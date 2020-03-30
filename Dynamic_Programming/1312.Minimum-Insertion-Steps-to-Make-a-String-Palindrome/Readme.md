### 1312.Minimum-Insertion-Steps-to-Make-a-String-Palindrome

#### 解法1：
第一种方法是：我们将原数列s逆序得到t。本题的答案等同于求这两个字符串的shortest common supersequence (SCS)。

这个转换其实并不容易理解。我们只能大概地有一种直观的感受：因为s和t是逆序关系，s最后一个字符等于t的第一个字符，应该让s放置于t的前面，尽可能地重合s的尾部和t的头部来提高字符重用的利用效率。所以最终s和t的SCS应该是个回文串。既然SCS的第一个S是shortest的意思，那么这个SCS就是通过s可以得到的最短的回文串。

这么转换之后，本题就是```1092.Shortest-Common-Supersequence```.

#### 解法2：
另一种更容易理解和想到的方法是区间型DP：定义dp[i][j]表示区间s[i:j]变成回文串最少需要多少添加多少字符。状态转移方程很容易理解：
```cpp
if (s[i]==s[j])  
  dp[i][j]=dp[i+1][j-1]; 
else 
  dp[i][j] = min(dp[i+1][j]+1,dp[i][j-1]+1) 
  // 前者表示让s[i+1:j]已经成为回文串，再在s[j]后添加一个与s[i]相同的字符使得s[i:j]变成回文串
  // 前者表示让s[i:j-1]已经成为回文串，再在s[i]前添加一个与s[j]相同的字符使得s[i:j]变成回文串
```

[Leetcode Link](https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome)
