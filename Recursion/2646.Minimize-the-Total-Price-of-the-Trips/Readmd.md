### 2646.Minimize-the-Total-Price-of-the-Trips

首先我们遍历所有的trip，记录每个节点被访问的次数count[i]，这样每个节点的实际price就是`price[i]*count[i]`，也就是说没有访问过的节点其实不贡献price。

之后就是常见的house-robber的套路。对于每个节点node，我们考察“不可以取半价”和“可以取半价”两种状态下可以得到的子树的最小price，分别记做plan0[node]和plan1[node]。

如果node本身不可以取半价，那么自然它的所有孩子都可以取半价。即`plan0[node] = price[node] + sum(plan1[child])`.

如果node本身可以取半价，那么它就对应两种策略：即真的取半价，对应地它的所有孩子都不可以取半价；或者它仍然不取半价，对应地它的所有孩子都可以取半价。两者取小为最优策略。以此递归下去求出每个节点的plan0和plan1. 即`plan0[node] = min(price[node] + sum(plan1[child]), price[node]/2 + sum(plan0[child])`.
