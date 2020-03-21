### 780.Reaching-Points

本题的突破点在于，x和y都是正数！于是，当我们发现tx>ty时，我们一定可以推断出，其之前的状态必须是(tx-ty,ty)并且执行了(x+y,y)的操作；这是因为如果执行了另一种操作，其结果不可能使得第一个分量大于第二个分量。同理，如果我们发现tx<ty时，我们一定可以推断出，其之前的状态必须是(tx,ty-tx)并且执行了(x,y+x)的操作。那么如果tx==ty呢？这是不可能的，因为(x,x+y)或者(x+y,y)都不可能有两个相等的分量。

于是我们可以写出如下的递归方法：
```cpp
  if (tx>ty) return reachingPoints(sx,sy,tx-ty,ty);
  else if (tx<ty) return reachingPoints(sx,sy,tx,ty-tx);
  else return false;
```
我们可以再做进一步的优化。当```tx>ty```时，我们知道其之前的状态是```(tx-ty,ty)```。那么如果此时依然有```tx-ty>ty```呢？同理推出，再之前的状态就是```(tx-2ty,ty)```。那么如果此时依然有```tx-2ty>ty```呢？同理推出，再之前的状态就是```(tx-3ty,ty)```...我们就可以一直进行下去，直至第一个分量小于第二个分量。而这个终结的状态，其实就是```(tx%ty,ty)```!

于是效率更高的递归方法是：
```cpp
  if (tx>ty) return reachingPoints(sx,sy,tx%ty,ty);
  else if (tx<ty) return reachingPoints(sx,sy,tx,ty%tx);
  else return false;
```


[Leetcode Link](https://leetcode.com/problems/reaching-points)