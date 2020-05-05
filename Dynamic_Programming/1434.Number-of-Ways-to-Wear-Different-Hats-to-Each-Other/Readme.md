### 1434.Number-of-Ways-to-Wear-Different-Hats-to-Each-Other

这道题是一道典型的背包+状态压缩的DP问题。

最初的想法是将帽子作为状态。也就是用一串01向量来表示第i顶帽子是否被人taken了。大致的算法是:
```cpp
for (int p=0; person < n; person++)
  for (int state = 000...000; state <= 111..111; state++)
  {
      for (int hat : HatsForThisPerson[p])
      {
          if (hat has been taken in state)
            continue;
          dp_new[state + hat] += dp[state]
      }
  }
```
最终的答案是在所有的state里面找出那些恰好有10个1的那些，取这些dp[state]的和。

但是这个方法有两大问题。首先state太大，有2^40种，第二层循环太复杂。其次，最终的答案要取C(40,10)种可能，也不实际。

比较巧妙的思路是看到人的数量最多只有10，用它来做状态非常合适。我们改定义为：用一串01向量来表示第i个人是否已经take苗子了。大致的算法是：
```cpp
for (int h = 0; h < 40; h ++)
  for (int state = 000...000; state <= 111..111; state++)
  {
      for (int person : PersonsForThisHat[h])
      {
          if (person has taken hat in state)
            continue;
          dp_new[state + person] += dp[state]
      }
  }
```
最终的答案就是dp[111...111]
