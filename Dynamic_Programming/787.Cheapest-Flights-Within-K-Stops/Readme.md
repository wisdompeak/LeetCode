### 787.Cheapest-Flights-Within-K-Stops

Floy算法的本质就是DP。复习一下传统的Floy算法,需要三重循环:
```cpp
for(k=0;k<n;k++)
  for(i=0;i<n;i++)
    for(j=0;j<n;j++)
      if( e[i][k]+e[k][j]<e[i][j])
         e[i][j] = e[i][k]+e[k][j];
```
在此题中,还有一个总转机次数不超过K的限制,所以除了e[i][j]表示每两个城市之间的最短距离外,还需要创建t[i][j]来存储对应e[i][j]的转机次数.于是代码转化为
```cpp
for(k=0;k<n;k++)
  for(i=0;i<n;i++)
    for(j=0;j<n;j++)
      if( e[i][k]+e[k][j]<e[i][j] &&  t[i][k]+t[k][j]+1<=K)
      {
         e[i][j] = e[i][k]+e[k][j];
         t[i][j] = t[i][k]+t[k][j]+1;
      }
```
以上的算法行得通,但是最外层的循环是n次,等于把整张图完完整整的走了一遍,每两点之间都老老实实考察了一遍.但是题意说超过K次的转机次数就不用考虑了,所以这个算法的效率肯定还可以提高.

事实上,每一次转机的机会,都可以有更新所有的e[i][j]一次.那么总共K次转机的机会,只要更新所有的e[i][j]共K次即可.所以最外层的循环次数是K就行.在每次循环中,每张机票(a,b,cost)能够带来多少行程上的改进,可以用DP的思想: ```dp[src][b] = min(dp[src][b],dp[src][a]+cost[a][b])```

所以最终的代码很简单:
```py
dp_new = dp
for k in range(K+1):
  for (a,b,cost) in flight:
    dp_new[b] = min(dp_new[b],dp[a]+cost)
```


[Leetcode Link](https://leetcode.com/problems/cheapest-flights-within-k-stops)
