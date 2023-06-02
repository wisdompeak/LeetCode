### 2714.Find-Shortest-Path-with-K-Hops

此题和`2093.Minimum-Cost-to-Reach-City-With-Discounts`几乎一样。我们用Dijkstra求最短距离时需要有两个参量，即`dist[node][hops]`表示还剩hops机会时node离原点的最短距离。当某状态向量`(dist, node, hops)`弹出队列时，我们可以加入两种相邻的状态`{dist+weight, nxt, hops}`或者`{dist, nxt, hops-1}`.

注意当PQ第一次弹出destination时，无论hops是多少，即可以输出最短距离。
