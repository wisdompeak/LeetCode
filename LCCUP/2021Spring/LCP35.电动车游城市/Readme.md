### LCP35.电动车游城市

我们将{cost, city, battery}作为节点建图，其中battery表示存留的电量。起点是{0, start,0}，终点是{x, end, x}. 用Dijkstra算法求起点到终点的最短距离。

记每次弹出优先队列的节点是{cost, curCity, curBat}，那么它有两类后继节点：
1. 原地充电：{cost+b, curCity, curBat+b}，其中```curBat+b<cnt```。
2. 开往邻接城市: {cost+len, nxtCity, curBat-len}，其中```curBat>=len```.

