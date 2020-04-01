### 1278.Palindrome-Partitioning-III

这是DP中一类典型问题的代表。题目会明确提到要分割为若干个（或者最多K个）连续子区间（subarray)，然后让你求这些区间的一些性质。

针对这种类型的套路是：设计dp[i][k]表示将s[0:i]分割为k个连续子区间能过够得到的性质。结合这道题的题意，就是指 the minimal number of characters that you need to change to divide the strings[0:i] into k subarrays.

转移方程的最外两层循环分别是遍历末尾元素i和分割的子区间个数k。转移方程中的突破点就是遍历搜索“最后一个”区间的位置！因此内部需要多一个循环来遍历j，这个j一定是在i之前，使得s[i:j]是最后一个区间。这样我们可以把dp[i][k]的问题分割成dp[i-1][k-1]和s[i:j]这两部分来考虑，而前者应该是已经求解过的子问题。
```cpp
          for (int i=1; i<=n; i++)
            for (int k=1; k<=min(i,K); k++)
            {
                dp[i][k] = INT_MAX;
                for (int j=k; j<=i; j++)
                {
                    dp[i][k] = min(dp[i][k], dp[j-1][k-1] + count[j][i]); 
                }
            }
```
其中count[j][i]表示对于区间s[j:i]我们需要多少次替换能够使其变成回文串。这个数可以用一个函数来实时计算，也可以提前用另一个DP算法处理好存在count里。这里就不细说了。

关于DP的初始化和边界条件，可以看出dp[0][0]需要特别处理，不难想到应该赋值为0.
