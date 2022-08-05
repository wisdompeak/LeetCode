### 2359.Find-Closest-Node-to-Given-Two-Nodes

本题就是直观的模拟。我们只要遍历所有的节点，查看它到node1的距离与它到node2的距离即可。那么这两个距离怎么求呢？我们事实上只要从node1开始无脑走一遍，就可以得到任意节点i到node1的距离dist1[i]，同理也可以得到任意节点到node2的距离dist2[i]。我们把这两个距离数组都保存下来，再遍历所有的i，求出最小的`max{dist1[i], dist2[i]}`即可。
