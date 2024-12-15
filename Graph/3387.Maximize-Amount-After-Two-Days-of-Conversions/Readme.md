### 3387.Maximize-Amount-After-Two-Days-of-Conversions

考虑到货币的种类只有20种，我们似乎可以用暴力的方法求出每天任意两种货币之间的最大汇率。于是我们可以想到使用o(n^3)的Floyd算法，看做是求图中任意两点之间的最大距离。

Floyd的具体做法是，每次引入一条边，然后将全局网络做一遍松弛：
```
for ([a,b]: edges)
  for (int i=0; i<n; i++)
    for (int j=0; j<n; j++)
      dist[i][j] = max(dist[i][j], dist[i][a]+edge[a][b]+dist[b][j]);
      dist[j][i] = max(dist[j][i], dist[j][a]+edge[a][b]+dist[b][i]);
```

有了两天各自任意两种货币之间的最大汇率`dist1`和`dist2`之后，枚举第一天结束的中介货币k，本题求的就是最大的`dist1[s][k]*dist2[k][s]`.

需要注意的细节是：
1. a->b的路径长度（汇率）是t的话，必然有b->a的路径长度是1/t，别忘了将其也加入图优化的松弛过程。
