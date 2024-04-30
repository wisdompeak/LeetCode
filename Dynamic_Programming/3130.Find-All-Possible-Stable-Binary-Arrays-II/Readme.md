### 3130.Find-All-Possible-Stable-Binary-Arrays-II

#### 解法1：
对于每一步决策而言，我们需要考虑的因素无非就是：已经用了几个0，已经用了几个1，当前最后一步是0还是1. 事实上，我们就用这些状态作为变量，即可定义动态规划。令dp0[i][j]表示已经用了i个0、j个1，并且最后一个数字填写的是0时，可以构造的stable binary array的个数。类似地，令dp1[i][j]表示已经用了i个0、j个1，并且最后一个数字填写的是1时，可以构造的stable binary array的个数。

如何计算dp0[i][j]呢？因为最后一步填0，且唯一的限制就是不能有连续超过limit+1个0，所以它之前最后一次出现的1，必须在`i+j-limit, i+j-limit+1, ..., i+j-1`中间的一处。所以就有
```
dp0[i][j] = dp1[i-limit][j] + dp1[i-limit+1][j] + ... + dp1[i-1][j]
```
同理，dp1[i][j]的前趋状态取决于最后一次出现0的位置，
```
dp1[i][j] = dp0[i][j-limit] + dp1[i][j-limit+1] + ... + dp1[i][j-1]
```
综上，我们用三层循环就可以求出dp0和dp1。最终答案就是将所有的0和1用完，但结尾的元素可以是0或1，即`dp0[zero][one]+dp1[zero][one]`.
```cpp
for (int i=0; i<=zero; i++)
  for (int j=0; j<=one; j++)
  {
     for (int k=1; k<=limit; k++)
     {
       if (i>=k) dp0[i][j] += dp1[i-k][j];
       if (j>=k) dp1[i][j] += dp0[i][j-k];
     }
  }
```

#### 解法2：
注意到上述解法的最内层循环，其实dp0[i][j]是累加了dp1[...][j]的一段区间，区间范围是[i-min(i,limit), i-1]. 同理，dp1[i][j]是累加了dp0[i][...]的一段区间，区间范围是[j-min(j,limit), j-1]. 为了节省这层循环，我们想到可以用前缀和。

令`presum0[i][...]`表示`dp0[i][...]`的前缀和，`presum1[j][...]`表示`dp1[...][j]`的前缀和。于是区间之和就可以表示成前缀和之差：
```
dp0[i][j] = presum1[j][i-1] - presum1[j][i-min(i,limit)-1]
dp1[i][j] = presum0[i][j-1] - presum0[i][j-min(j,limit)-1]
```
用完之后，记得将新算出的dp0[i][j]和dp1[i][j]来更新presum0与presum1
```
presum0[i][j] = presum0[i][j-1] + dp0[i][j]
presum1[j][i] = presum1[j][i-1] + dp1[i][j]
```
就这样在i与j的双层循环里，不断滚动更新dp0[i][j]、dp1[i][j]、presum0[i][j]与presum1[j][i].
