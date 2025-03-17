### 3489.Zero-Array-Transformation-IV

这本质是一个背包问题。每处理一个query，在对应区间内的nums[i]就多得了一次删减的操作。

我们需要查看这些nums[i]在获得这个额外的删减机会之后，是否能连同之前的删减操作，实现置零？很显然，如果该query能够让nums[i]再削减d，那么就取决于nums[i]之前能否削减至d。

我们令dp[i][v]表示如果nums[i]的数值是v，能否最终削减成为零。就有
```
for q: queries
  a = q[0], b = q[1], d = q[2];
  for (i=a; i=b; i++) {
     for (int v=0; v<=1000; v++) {
         dp[i][v] = dp[i][v] || d[i][v-d];
     }
  }
```
最终查看所有的dp[i][nums[i]]是否为true。
