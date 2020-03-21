### 269.Alien-Dictionary

这是一道很典型的需要拓扑排序的问题．拓扑排序，说的是给出一系列的有向边，要求给出一个包括所有节点的顺序排列，使得任何有两边的两个节点在这个排序里，都是起点在前，终点在后．

这种排序适合ＢＦＳ来做．我们需要预处理所有的节点，得到所有节点的入度值．在队列的初始值里，加入所有入度为零的节点．在BFS过程中，不断减小各个节点的入度，而入度减至零的节点就可以加入队列中．

基本算法如下：
```
while (!q.emtpy())
{
   char current = q.front();
   q.pop();
   for (auto next: Next[current])
   {
      inDegree[next]--;
      if (inDegree[next]==0)
        q.push(next);
   }
}
```


[Leetcode Link](https://leetcode.com/problems/alien-dictionary)