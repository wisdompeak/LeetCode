### 743.Network-Delay-Time

#### BFS
此题和＂913　Cat and Mouse＂一样，扩展了我们对于BFS的认识．BFS的节点的状态可以是多个参数的．在这里，队列里每个节点的状态表示为```(node,ArrivalTime)```.注意，这里的ArrivalTime是只入队列时候的．此外，我们还需要一个map，来记录每个节点当前最新的earliestArrivalTime，这个是实时更新的．

我们取出一个节点，查看它的ArrivalTime是否能给它的邻接点带来时间上的更新．也就是比较```ArrivalTime+weight < earliestArrivalTime[nextNode]```，是的话，我们就更新nextNode并且把这个新状态```(nextNode,ArrivalTime+weight)```加入队列．

当队列为空时，说明没有什么可以更新的了．此时查看map里存放的就是每个节点的最终earliestArrivalTime．

#### Floyd
求两点之间的最短路径，典型的图论中的基本算法。Floyd是我的首选，因为代码短，容易理解，而且对于边权的值没有正数的限制。本质就是轮遍所有的节点k看是否能对dp[i][j]的更新做贡献。即 ```dp[i][j] = min(dp[i][j], dp[i][k]+dp[k][j])```


[Leetcode Link](https://leetcode.com/problems/network-delay-time)