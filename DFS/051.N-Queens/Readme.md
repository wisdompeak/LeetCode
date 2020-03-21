### 051.N-Queens

经典的八皇后问题，用DFS实现的回溯算法。

根据题目的性质，整个棋盘的布局其实可以用一个一维数组就可以表示:
```
vector<int>Q_pos(n); // Q_pos[row]的数值表示第row行可以摆放皇后的位置。
```
在第row行找到一个可行的摆放位置后，就可以把找第row+1行的任务交给递归函数去做就行了。核心代码如下：
```
for (int col=0; col<n; col++)
{
    if (isValid(Q_pos,row,col)
    {
       Q_pos[row]=col;
       DFS(Q_pos,row+1,results);
       Q_pos[row]=-1;
    }
}
```
之所以称之为回溯算法，是因为对于每一行row，可能有若干个候选位置col，需要平行地探索。所以对每个col进行DFS后，都需要重置Q_pos[row]的数值，顾名思义就是重新来一遍。


[Leetcode Link](https://leetcode.com/problems/n-queens)