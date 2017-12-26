### 518.Coin-Change-2

此题很容易想到DP的解法，但是非常容易出错。

用dp[i]表示总数额为i的硬币组合数目。那么显然有动态转移方程:
```cpp
for (j=0; j<coins.size(); j++) 
    dp[i] += dp[i-coins[j]]
```
那么对于i=0~amount的循环应该放在哪里呢？这样的框架是错误的：
```cpp
for (int i=0; i<=amount; i++)
  for (j=0; j<coins.size(); j++) 
    dp[i] += dp[i-coins[j]];
```
举个例子：总数额为3时，1+2 和 2+1 的两种方法就会重复计算。所以我们必须把两个外循环的框架反过来：
```cpp
for (j=0; j<coins.size(); j++) 
  for (int i=0; i<=amount; i++)
    dp[i] += dp[i-coins[j]];
```
这样，我们保证了最后一步总是加入coins[j]，这样得到的dp[i]对应的所有方案都不会是重复的（对于使用coins[0]~coins[j]而言）。
