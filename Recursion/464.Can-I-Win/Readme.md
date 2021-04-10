### 464.Can-I-Win

本题最关键的一点是想到要用递归。如果列举自己的所有决策，对手都是mustWin==true，那么自己的mustWin就是false；反之，自己的某一个决策能够使得对手的mustWin==false，那么就是自己mustWin就是true。想到这一点的话，大致的代码如下：
```cpp
for (int i=1; i<=maxChoosableInteger; i++)
{
    if (used[i]==1) continue;  // 跳过已经使用过的数字
    used[i]=1;
    if (DFS(maxChoosableInteger,desiredTotal-i)==false)  // 如果下一轮（注意是对手轮）是必输决策，那么说明本轮该决策必赢
       return true;
    used[i]=0;
}
return false; // 遍历了本轮所有的决策后都没有跳出，说明对方都有必赢决策，那么本轮对自己而言就是必输。
```
但不幸的是，以上的代码会超时。原因是每轮的决策都是近乎随机的，N轮之后会造成大量重复的决策。比如对于第三轮（我方）而言：第一轮（我方）取1，第二轮（对方）取2；这个完全等效于第一轮（我方）取2、第二轮（对方）取1。如果对于前者DFS完毕之后，其实就不需要再对后者进行相同的DFS了。所以很明显，需要利用到记忆化搜索，也就是把之前DFS得到的一些中间结果存储下来。

本题的“中间结果”是指：在已经取走一些数字的情况下，自己做决策是会必输还是有办法包赢。所以我们需要一个Hash表，key应该是已经取数的状态，val就是bool型表明对于这种状态本方是赢还是输。怎么将已经取了哪些数的“状态”作为一个key呢？考虑到最多只有20个数，用一个20位的二进制数字就可以表示所有取数状态了。
```cpp
int status=0;
for (int i=1; i<=maxChoosableInteger; i++)
{
  if (((status>>i)&1)==1) continue; // 跳过已经使用过的数字
  if (DFS(maxChoosableInteger,desiredTotal-i, status|(1<<i))==false) // 如果下一轮（注意是对手轮）是必输决策，那么说明本轮该决策必赢
  {
     Map[status]=true;
     return true;
  }    
}
Map[status]=false; // 遍历了本轮所有的决策后都没有跳出，说明对方都有必赢决策，那么本轮对自己而言就是必输。需要记录下来，免除后续的重复搜索。
return false; 
```

上面这种每一轮互相易手的游戏规则，求最终必胜或必输策略的问题，常常被称为minMax问题。基本思路就是：当前状态下，列举自己的每一种策略，如果对方都有必胜的应手，那么本方的这个状态就是必输。如果自己有一手策略，会导致对方必输，那么本方的这个状态就是必赢。


[Leetcode Link](https://leetcode.com/problems/can-i-win)