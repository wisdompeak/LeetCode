### 743.Network-Delay-Time

此题和＂913　Cat and Mouse＂一样，扩展了我们对于BFS的认识．BFS的节点的状态可以是多个参数的．在这里，队列里每个节点的状态表示为```(node,earliestArrivalTime)```.注意，这里的earliestArrivalTime是只入队列时候的．此外，我们还需要一个map，来记录每个节点当前最新的earliestArrivalTime，这个是实时更新的．

我们取出一个节点，查看它的earliestArrivalTime是否能给它的临界点带来时间上的更新．也就是比较```earliestArrivalTime+weight < map[nextNode]```，是的话，我们就更新nextNode并且把这个新状态```(nextNode,earliestArrivalTime+weight)```加入队列．

当队列为空时，说明没有什么可以更新的了．此时查看map里存放的就是每个节点的最终earliestArrivalTime．
