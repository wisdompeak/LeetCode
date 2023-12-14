### 2959.Number-of-Possible-Sets-of-Closing-Branches

因为节点数目n只有10，所以我们可以暴力枚举所有的closure方案，只需要2^n不超过1024种。

对于每种closure的方案，我们可以用类似Floy算法的n^3的时间度算出任意两点间的最短距离（排除掉closed point），然后只需要检查是否都小于targetDistance即可。

Floyd松弛算法如下：
```cpp
for road : roads
  int a = road[0], b = road[1], w = road[2];
  for (int i=0; i<n; i++)
    for (int j=0; j<n; j++)
      d[i][j] = min(dp[i][j], dp[i][a]+w+dp[b][j]);
      d[i][j] = min(dp[i][j], dp[i][b]+w+dp[a][j]);
```
