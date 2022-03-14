### 2203.Minimum-Weighted-Subgraph-With-the-Required-Paths

本题的路径模式抽象起来其实就只有一种：就是分别从src1和src2出发的两条路径在某个位置交汇（记做M），然后再从M连通到target。所以本题就是找一个M点，使得M到三个位置（src1，src2，target）的最短路径之和最小。很显然，调用三次Dijkstra算法即可，每次调用求得全局任何位置到指定起点的最短路径，并将其记录下来。
