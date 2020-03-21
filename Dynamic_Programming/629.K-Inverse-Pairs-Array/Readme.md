### 629.K-Inverse-Pairs-Array

有一定难度的DP题。

约定dp[n][k]表示从1~n的任意排列中inverse pair数目为k的组合数目。
```
For example, if we have some permutation of 1...4   
5 x x x x creates 4 new inverse pairs   
x 5 x x x creates 3 new inverse pairs   
...   
x x x x 5 creates 0 new inverse pairs   
```
如上的例子：    
假设xxxx代表dp[4][j]的所有排列可能。易知xxxx5并不会增加inverse pair的数目，所以dp[4][j]是dp[5][j]的一部分。   
假设xxxx代表dp[4][j-1]的所有排列可能。易知xxx5x增加了一个inverse pair的数目，所以dp[4][j-1]是dp[5][j]的一部分。   
假设xxxx代表dp[4][j-2]的所有排列可能。易知xx5xx增加了两个inverse pair的数目，所以dp[4][j-2]是dp[5][j]的一部分。   
假设xxxx代表dp[4][j-3]的所有排列可能。易知x5xxx增加了三个inverse pair的数目，所以dp[4][j-3]是dp[5][j]的一部分。   
假设xxxx代表dp[4][j-4]的所有排列可能。易知5xxxx增加了四个inverse pair的数目，所以dp[4][j-4]是dp[5][j]的一部分。   

所以，可以得到递推关系是：
```cpp
dp[i][j] = dp[i-1][j]+dp[i-1][j-1]+dp[i-1][j-2]+...+dp[i-1][j-i+1]
```
直接用上述的递推关系仍然会超时。这个递推关系还可以进一步简化。考虑
```cpp
dp[i][j-1] = dp[i-1][j-1]+dp[i-1][j-2]+...+dp[i-1][j-i]
```
将dp[i][j-1]带入dp[i][j]，可以得到
```cpp
dp[i][j] = dp[i-1][j]+dp[i][j-1]-dp[i-1][j-i]
```
需要注意的是，上述关系式仅当j>=i时才有dp[i-1][j-i]。否则，最后一项省略。

另外，dp的边界条件是d[i][0]=1，表示没有任何inverse pair的排列只有一种，那就是从小到大顺序排列。


[Leetcode Link](https://leetcode.com/problems/k-inverse-pairs-array)