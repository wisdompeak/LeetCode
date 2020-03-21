### 130.Surrounded-Regions

#### BFS
此题用BFS的想法会更直接。找到所有在边界上的O点，以其为基础做BFS的扩散，标记为#。最后，所有剩余的O都转化为X。

注意，在BFS队列的处理中，进队列的时候就标记#，而不是在出队列的时候。这样能够避免很多各自的重复入列。

#### Union Find
遍历时忽略所有的X，仅对所有的O进行集合编组。注意，在初始编组中，我们对所有在边界上的O点统一编组为-1，非边界上的O点编组序号为其本身的index。

在第二遍遍历的过程中，我们对所有想邻接的O点进行Union。Union的规则其实不需要改动，因为-1永远比任何index而言都是最小的，按照最小编号进行Union的法则，所有与边界相通的O点都可以最终归为-1. 但要注意的是，在FindSet的操作中需要特殊的操作，需要判断```if (Father[x]==-1) return -1;```因为对于与边界相邻的O点，其递归的终点不是```x==Father[x]```而是-1.


[Leetcode Link](https://leetcode.com/problems/surrounded-regions)