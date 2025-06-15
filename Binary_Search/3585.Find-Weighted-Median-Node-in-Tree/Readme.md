### 3585.Find-Weighted-Median-Node-in-Tree

对于任何一个query，我们只需要找到u到v路径（途中经过LCA的点记作c），假设路径的总步长是d，路径的总权重和是total。我们只需要在[0,d]之间进行二分搜索一个合适的步数k：即从u走k步，恰好走过的路径长度超过total的一半。

注意，我们在二分搜索对k进行判定的时候，需要分类讨论k是否在u到c的路径上，还是c到v的路径上。即看是否`dist(u,c) >= total * 0.5`. 如果k是在u到c的路径上，那么经过的路径长度就是dist(u,k)。如果k是在c到v的路径上，那么经过的路径长度就是dist(u,c)+dist(c,k)。

根据binary lifting的算法，树里任意两个节点之间的距离都可以用log(n)的时间求解。
