### 684.Redundant-Connection

考虑这些edges所组成的网络是个无向图。那么这个图是tree的充要条件是：所有节点到另外一个节点的通路有且仅有一条。

所以从前往后遍历edges，一旦发现某个edge的两个点，已经在之前的遍历中是联通的了，那么这个edge的加入就会导致“树”定义的不成立，故必须除去。根据题意，保证了只有唯一的答案，故就不用继续往后查下去了。

于是本题就是一个考察union find的基本题。两个基本操作要熟练：
```cpp
int FindSet(int x)
{
   if (x!=Father[x])
   {
      Father[x]=FindSet(Father[x]);
   }
   return Father[x];
}
```
```cpp
void Union (int x, int y)
{
   x=Father[x];
   y=Father[y];
   if (x<y)
      Father[y]=x;
   else
      Father[x]=y;
}
```
在遍历edges的过程中
```cpp
   int x=edges[i][0];
   int y=edges[i][1];
   if (FindSet[x]==FindSet[y])  //注意，不是 if (Father[x]==Father[y])，因为Father[x]可能还没更新到这个集合的根。
      return edges[i];
   else 
      Union(x,y);
```


[Leetcode Link](https://leetcode.com/problems/redundant-connection)