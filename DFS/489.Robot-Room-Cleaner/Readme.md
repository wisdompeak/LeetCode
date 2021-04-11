### 489.Robot-Room-Cleaner

本题看上去是一个常规的DFS，但是难点在于机器人的运动是第一视角，DFS的回溯过程必须靠“手工”实现。

假设当前我们访问了dfs(x,y,north)，表示当前位置是(x,y)，朝向是北。如果我们想递归访问它的东边的节点(i,j)，你需要依次做如下的事情：
```
1. 向右转，使得朝向东边，
2. 前进
3. 递归调用dfs(i,j,east)
4. 180度转弯
5. 前进
6. 180度转弯
=====
8. 向右转，使得朝向南边
9. 前进
10. 递归调用dfs(i,j,south)
11. ...
```
可见我们完成一次dfs之后，必须手工完成掉头、退回、调整方向，才能进行另一次平行的dfs尝试。


[Leetcode Link](https://leetcode.com/problems/robot-room-cleaner)
