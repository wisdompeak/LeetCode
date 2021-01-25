### 1724.Checking-Existence-of-Edge-Length-Limited-Paths-II

#### 解法1
本题看上去和```1697	Checking Existence of Edge Length Limited Paths```很像，但是做法却有很大的差别。本题要提供online的查询，每次查询时刻所对应的union tree都是不一样的形状。如果是Limit较大的query，那么图里面就有更多的联通点；反之，图里面就有更少的联通点。

所以本题的关键，就是将不同limit所对应的连通图都要记录下来。这里对“连通图”的记录其实并不复杂，本质就是记录各个点的father即可。Limit较大时，有更多节点的father被聚合到了一起；反之，就有更多节点的father只是自己。如何记录每个node在不同limit时对应的father呢？这其实是采用了与```1146	Snapshot Array```相同的技巧：给每个节点创建father的时间序列快照。

我们定义```snaps[node]={{snapId1, father1}, {snapId2, father2}, ...}```来记录node在不同快照时刻的父节点。所谓的快照时刻snapId，就是对应limit增长的过程。我们想象，随着limit的提升，会有越来越多的节点被联通，相应地那些被联通的node的father就会有变化。事实上，我们所关心的limit的提升是离散的，limit只在变化到某些特定的阶跃值时才会对连通图产生影响，这一系列阶跃值其实就是所有edges（排序后）的长度。比如，当limit=edge[0]时，并没有任何点被联通；当limt = edge[1]时，至少有两个点（也可能更多）被联通...

我们将edges排序之后，就可以知道哪些阶跃值会影响连通图，我们依次标记快照时刻为0,1,2,3...比如说，快照时刻0表示Limit=edge[0]的时刻。注意，edges可能有重复值，所以我们关注的快照时刻的数量很可能会比edges的数目要少。我们只对应edges里面unique的长度来拍快照。

具体的预处理如下：
1. 我们逐个考察每个快照时刻snapId对应的limit，将小于limit的边收入连通图中，这样会导致一些节点被union。
2. 假设节点a和b要被union，那么我们就将各自的祖宗节点fa和fb找出来（通过findFather的递归）。此时为了将两大家族合并，我们要么将fa的父亲指向fb，或者将fb的父亲指向fa。那么哪个更好呢？这就用到了Union Find里与“路径压缩”不同另外一个处理方法：按秩排序。所谓某个节点的“秩”，就是它与离自己最远的叶子的距离。我们会将fa和fb中秩更大的那个节点，选为两大家族合并后的代表（假设是fa）。这样的好处是，union之后```rank[fa] = max(rank[fa], rank[fb]+1)```有可能并不会继续增大，这意味着以fa为根节点的树会更“平衡”一些。这样在这棵树里的任何节点做findRoot（找根节点）所需要的递归次数就会相对少一些。注意，本题中我们不会做任何“路径压缩”，我们要原原本本的保留每个节点的原始父节点（因为需要存储快照）。
3. 当节点a和b被union之后，意味着fb的father就要更新为fa.这个变动要存储在snaps[fb]相应的快照记录中，即```snaps[fb].push_back({snapId, fa}```.

处理query时我们需要：找出limit所对应的snap_id，然后寻找节点p在snap_id时刻的根节点、节点q在snap_id时刻的根节点，查看是否相等。同样，查找特定快照时刻的根节点，需要递归调用```findSnapFather(node, snap_id)```。

#### 解法2
针对解法1可以有一点小改进。我们在构造snaps[node]的时候，可以用当前所用边的长度的作为snapId，不需要另行维护一个自增1的snapId变量。在query()中，我们直接用limit在snaps[node]里面二分搜寻合适的snapId，注意这里定位iter的方法应该是```lower_bound({limit,0})-1```.
