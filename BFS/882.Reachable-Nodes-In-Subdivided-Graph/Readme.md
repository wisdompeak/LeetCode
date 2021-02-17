### 882.Reachable-Nodes-In-Subdivided-Graph

我们可以用Dijkstra求出从0点到任意原始节点i的最短距离（最少需要的moves），记为dist[i]。那么这个结果对于解题有什么帮助呢？

我们令edgeVisitedNodes[i][j]表示从i->j这条边，我们最多能再走几步（即访问多少个“细分点”）。因为总的maxMoves是固定的，我们自然希望到达i点时用的步数越少的话，那么我们在i->j这条边上能走的步数就越多。也就是说，我们能在i->j这条边上再走```maxMoves-dist[i]```步。注意，我们只考虑“细分点”而不考虑端点，因此这个数字不能超过这条边的cnt，即 ```VisitedSubNodes[i][j] = min(cnt, maxMoves - dist[i])```

同理，我们也可以求出我们能在j->i这条边上再走多少步，即 ```VisitedSubNodes[i][j] = min(cnt, maxMoves - dist[i])```。

有了以上的数据，我们再遍历所有的边```i<->j```，那么除了两个端点，我们能在这条边上访问到的“细分点”数目应该是```min(VisitedSubNodes[i][j]+VisitedSubNodes[j][i], cnt)```. 我们另外从dist[i]统计所有能走到的端点。最终答案是两者之和。
