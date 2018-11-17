###  730.Count-Different-Palindromic-Subsequences

此题最大的特点是，不同的回文序列的定义是：只有字符不同的才算不同．所以我们定义dp[i][j]的时候，往内层递归时，需要分四种字符来讨论．

假设我们在考察dp[i][j].我们需要额外定义first[i][k]，表示第i个字符开始，往后第一次出现k的位置．同理last[j][k]，表示第j个字符开始，往前最后一次出现k的位置．显然，这里的first[i][k]和last[j][k]都是在闭区间[i,j]里面．

所以可以有转移方程：
```cpp
for (int k=0; k<4; k++)
  dp[i][j]+= dp[first[i][k]+1][last[i][k]-1];
```
注意，上述的方程不够完善．因为可能first[i][k]或second[i][k]不存在．所以更完善的表达是：
```cpp
for (int k=0; k<4; k++)
{
  if (last[i][k]!=-1)
    dp[i][j]+= dp[first[i][k]+1][last[i][k]-1];
  if (first[i][k]!=-1)
    dp[i][j]+= 1;
}
```
第二个判断语句是因为，字符ｋ在[i,j]区间内不能和另外一个匹配成回文，但是它自身可以单独出现作为回文．所以dp[i][j]需要自加１．
