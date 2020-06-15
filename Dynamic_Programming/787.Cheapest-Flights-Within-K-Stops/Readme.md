### 787.Cheapest-Flights-Within-K-Stops

### 解法1：
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
很不幸，以上的算法是错误的。周赛过后补充了一个例子：[[0,1,1],[0,2,5],[1,2,1],[2,3,1]]

当要求最多转1次（即两趟飞机），从0到3的最小代价。事实上的解是: 0->2->3，代价是5+1=6. 但是上面的算法返回的却是无解。这是因为前半段0->2的行程，floyd提前算出来的最优解是0->1->2，因为代价最小(1+1=2)，但是需要转机两次。所以再加上2->3这段时，因为转机的次数限制，被算法判断为无解。

### 解法2：
我们可以利用dp的思想。令dp[k][b]表示从起点做k次飞机能过够到达城市b的最小代价。显然，它之前的状态就是做k-1次飞机能到哪里。于是我们有状态转移方程：
```
dp[k][b] = min(dp[k][b], dp[k-1][a] + cost[a][b]), where there is a flight from a to b.
``` 
所以最终的代码很简单:
```py
for k in range(K+1):
  dp_tmp = dp
  for (a,b,cost) in flight:
    dp[b] = min(dp[b],dp_tmp[a]+cost)
```

[Leetcode Link](https://leetcode.com/problems/cheapest-flights-within-k-stops)
