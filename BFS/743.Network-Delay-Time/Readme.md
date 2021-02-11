### 743.Network-Delay-Time

#### BFS
此题和＂913　Cat and Mouse＂一样，扩展了我们对于BFS的认识．BFS的节点的状态可以是多个参数的．在这里，队列里每个节点的状态表示为```(node,ArrivalTime)```.注意，这里的ArrivalTime是只入队列时候的．此外，我们还需要一个map，来记录每个节点当前最新的earliestArrivalTime，这个是实时更新的．

我们取出一个节点，查看它的ArrivalTime是否能给它的邻接点带来时间上的更新．也就是比较```ArrivalTime+weight < earliestArrivalTime[nextNode]```，是的话，我们就更新nextNode并且把这个新状态```(nextNode,ArrivalTime+weight)```加入队列．

当队列为空时，说明没有什么可以更新的了．此时查看map里存放的就是每个节点的最终earliestArrivalTime．

#### Dijkstra (BFS+PQ)
对于BFS，每一次扩展对应的只是“几何意义上的”层级的自增1，只适合寻找“最少步数”。如果每一步有权重（相当于边有权值）、求起点到终点最短权重总和的问题，那么传统的BFS就不太方便。

Dijkstra的本质就是将BFS的传统队列替换为优先队列，采用贪心的策略。每次从优先队列中弹出当前离起点最近的点cur，然后将它所有邻接的点以{dist, next}的形式加入队列，其中dist就是起点到cur的距离再加上cur->next的这条边权。我们有这样一个贪心的结论：如果某个节点第一次从这个优先队列中弹出来，它所对应的dist就是起点到该节点的最短距离。

这种方法的时间复杂度是ElogE. 通常情况下，如果不是稠密图，ElogE会比N^2有优势。

Dijkstra也有o(N^2)的实现方法。每个回合在所有的点中找到未收录的、离起点最近的那个节点，然后收录这个节点（确认这个节点的最短距离），并以这个节点更新它的所有邻接节点的距离。重复N个回合。

#### Floyd
求两点之间的最短路径，典型的图论中的基本算法。Floyd是我的首选，因为代码短，容易理解，而且对于边权的值没有正数的限制。本质就是轮遍所有的节点k看是否能对dp[i][j]的更新做贡献。即 ```dp[i][j] = min(dp[i][j], dp[i][k]+dp[k][j])```


[Leetcode Link](https://leetcode.com/problems/network-delay-time)
