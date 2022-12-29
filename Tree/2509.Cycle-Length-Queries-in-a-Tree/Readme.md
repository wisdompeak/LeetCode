### 2509.Cycle-Length-Queries-in-a-Tree

此题的本质就是找lowest common ancestor。本题的特殊之处在于每个节点指向其parent的路径其实非常简洁：val->val/2，数值是单调递减的。所以我们对于任意两个节点a和b，只要每次将其中的较小值减半，就一定最终让两者收敛一致，即LCA。减半操作的次数就是cycle的长度。
