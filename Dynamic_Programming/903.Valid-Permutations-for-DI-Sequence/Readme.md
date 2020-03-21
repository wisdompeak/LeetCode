### 903.Valid-Permutations-for-DI-Sequence

此题可以用DP来解决。首先我们做一些索引上的调整，方便我们理解：
```cpp
S = "#"+S;
N = S.size();
auto dp = vector<vector<int>>(N+1,vector<int>(N+1,0));
```
这里dp[i][j]表示第i位上（以0为起点）的数值为j的方案数目。这里，j的取值范围是0\~i。相当于0\~i的一个permuatation。

我们考虑在往第i位上填数时，显然应该受到S[i]的影响。

S[i]为“I”的时候，说明要求第i位上的数字要比第i-1位上的数字大。那么第i-1位上可以是什么呢？因为第i位上是j，那么第i-1位上只能是1~j-1.所以
```
if (S[i]=='I')
  for (int k = 0; k<j; k++)
    dp[i][j] += dp[i-1][k];
```
有人会问，dp[i-1][?]表示的是0\~i-1的permutation啊，而dp[i][?]表示的是0\~i的permutation啊。为什么0\~i-1的某个全排列接上一个任意的j，就可以是0\~i的全排列呢？其实我们只要将前i-1为的所有大于等于j的数字都抬高一位，给第i位上的j腾出空间来就行了。我们可以想象，将前i-1为的所有大于等于j的数字都抬高一位，对前i-1位的dp状态没有任何影响。

同理，S[i]为“D”的时候，说明要求第i位上的数字要比第i-1位上的数字小。那么第i-1位上的数是不是从j+1到i-1呢？其实不然，是从j到i-1都可以。为什么呢？我们也只需要将前i-1位大于等于j的数字都抬高一位即可。这样dp[i-1][j]就可以接上第i位的j了。
```
if (S[i]=='D')
  for (int k = j; k<=i-1; k++)
    dp[i][j] += dp[i-1][k];
```
最终的答案是dp[N][j]，将j从0到N遍历一遍，收集这个全排列最后一位的所有可能性，取和即可。


[Leetcode Link](https://leetcode.com/problems/valid-permutations-for-di-sequence)