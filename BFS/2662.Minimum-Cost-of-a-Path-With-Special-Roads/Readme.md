### 2662.Minimum-Cost-of-a-Path-With-Special-Roads

#### 解法2：Dijkstra
对于每条special road，它的起点其实都是无关紧要的，保底用start到其曼哈顿距离即可。只有这些special road的终点才是改变这张图拓扑关系的关键点（否则永远都是trivial的网格结构）。所以我们可以用Dijkstra算法，来更新start到各个road终点的最短距离。最后在所有的终点x里，挑一个最小的`start->x->target`的距离，其中`x->target`是曼哈顿距离。

更具体地，我们从pq里弹出当前某点p的最短距离len，那么我们就可以利用从x到y的road，更新从p到y的距离：`len + abs|p-x| + cost`.
