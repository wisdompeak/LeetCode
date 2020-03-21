### 583.Delete-Operation-for-Two-Strings

#### 解法1
此题可以转化为LCS(longest common sequence)，典型的DP算法的应用。

```dp[i][j]```表示word1的前i个元素、word2的前j个元素的最长共同元素数目。

递推关系：
```
dp[i][j] =   dp[i-1][j-1]+1              (if word1[i]==word2[j]) 
             max(dp[i-1][j],dp[i][j-1])   (if word1[i]!=word2[j])
```
最后的结果应该是 ```m+n-dp[m][n]*2```


#### 解法2

也可以直接根据题目的意思来设计状态变量。```dp[i][j]```就表示the minimum number of steps required to make ```word1[1:i]``` and ```word2[1:j]``` the same.

状态转移方程和上面很类似：
```
dp[i][j] =   dp[i-1][j-1]                   (if word1[i]==word2[j]) 
             min(dp[i-1][j],dp[i][j-1])+1   (if word1[i]!=word2[j])
```
最后的结果就是 ```dp[m][n]```

需要注意设置边界条件```dp[0][j]```和```dp[i][0]```.


[Leetcode Link](https://leetcode.com/problems/delete-operation-for-two-strings)