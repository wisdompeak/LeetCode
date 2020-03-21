### 1172.Dinner-Plate-Stacks

本题的关键就是维护两个索引指针，leftNotFull和RightNotEmpty。顾名思义，leftNotFull表示左边第一个没有放满的盘子的编号，rightNotEmpty表示右边第一个非空的盘子的编号。如果这两个索引指针维护的好，那么push和pop就是分别对应这两个盘子进行操作即可。

本题的关键是，任何的操作都需要对这两个指针进行更新和维护。

对于push(val)，意味着往leftNotFull上面再加一个数。如果该盘子满了，就要对leftNotFull进行自增操作来定位下一个非满的盘子。同时，rightNotEmpty也可能增长，基本原理是rightNotEmpty不可能比leftNotFull小（除非leftNotFull对应的是一个空盘子，那样的话rightNotEmpty==leftNotFull-1）。

对于popAtStack(index)，意味着对于index这个盘子要弹出一个数。这个操作会对leftNotFull有什么影响呢？显然，它就有被更新的可能，即```leftNotFull=min(leftNotFull,index)```。这个操作会对rightNotEmpty有什么影响呢？那就是当index==rightNotEmpty的时候，如果index这个盘子被清空了，则rightNotEmpty就要往下降（特别注意，最小降为-1为止）。

对于pop()，其实就是```popAtStack(rightNotEmpty)```。

特别注意，rightNotEmpty允许为-1，表示当前所有的盘子都为空。


[Leetcode Link](https://leetcode.com/problems/dinner-plate-stacks)