### 072.Edit-Distance

此题类似097.Interleaving String，用DP来实现两个数组的某项功能关系。用dp[i][j]分别表示数组A取前i位、数组B取前j位时的目标函数（所需的最小edit次数），想办法找出其与dp[i-1][j]或dp[i][j-1]或dp[i-1][j-1]或以上所有的递推关系。

对于dp[i][j]，常规思路是考虑数组A的第i位，数组B的第j位。一个最直接的想法是：如果word1[i]==word2[j]，那么显然dp[i][j]=dp[i-1][j-1]，轻而易举地把锅甩给了低一个量级的子问题。

那么如果word1[i]!=word2[j]呢？显然，若想递进到dp[i][j]的话，可以尝试从dp[i-1][j]入手：因为dp[i-1][j]表示word1[1\~i-1]和word2[1\~j]匹配的操作数，那么如果想再加上word1[i]并强行保持匹配，那么就只有将word1[i]删除这步操作。同理，考虑从dp[i][j-1]入手，将word2删除第j个字符即可等同于dp[i][j-1]的情况。第三个方案是从dp[i-1][j-1]入手，在此基础上将word1的第i个字符直接替换为word2的第j个字符，同样可以使两者匹配成功。

综上，粗浅的递推关系很容易写出来（以1为index的起点）：
```cpp
for (int i=1; i<=n1; i++)
 for (int j=1; j<=n2; j++)
 {
     if (word1[i]==word2[j])
        dp[i][j]==dp[i-1][j-1];
     else
        dp[i][j]=min(min(dp[i-1][j],dp[i][j-1]),dp[i-1][j-1])+1;     
 }
```
输出的结果是dp[n1][n2].

现在考虑边界条件。发现当i=1, j=1时，上述递推关系式中需要用dp[i][0] (for all i), dp[0][j] (for all j). 因此我们特别考虑一下他们。很明显dp[i][0]表示子串A有i位，子串B有零位，显然只需要在子串添加i个相应的字符即可匹配字符串A，所以dp[i][0]=i。同理，dp[0][j]=j。更特殊一点，dp[0][0]=0.


[Leetcode Link](https://leetcode.com/problems/edit-distance)