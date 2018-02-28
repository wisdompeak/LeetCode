### 488.Zuma-Game

此题并没有太多的技巧，就是暴力的深度搜索，遍历每次取的hand ball、以及它在board中可以插入的位置，更新得到newboard和newhand，然后不停地调用```DFS(newboard,newhand)```即可。

可以剪枝的地方有两处：
1. 手头的hand里面如果有若干个球是同色的话，那么只需要考察其中一个即可。也就是说，DFS的时候只遍历hand里面不同色的球。
2. 选定了一个hand ball之后，那么它在board里插入的位置也不是随意的。显然，如果将hand ball插入board里同色的位置肯定是较优的。也就是说对于hand[i]和board的位置j，如果```board[j]!=hand[i]```那么就直接跳过。
