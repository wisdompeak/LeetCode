### 1263.Minimum-Moves-to-Move-a-Box-to-Their-Target-Location

这道题可以用比较粗暴的BFS来实现。每个状态包括(bx,by,px,py)表示box和person的坐标，同时用一个四维数组flag[bx][by][px][py]来记录到达这个状态需要多少次移动（move）。

每次从队列中弹出一个状态，我们就遍历person朝四个方向可以变动的位置，再加入队列之中。注意到这个新状态对应的最少移动次数```flag[bx][by][px_new][py_new]=flag[bx][by][px][py]```不会变化，但如果我们仍然依照传统BFS的策略将这个新状态加入队列末尾，可能会导致队列中的状态所对应的move不是递增的，最终无法搜索到正确的最少move次数。解决方法是：用deque而不是queue，将这个新状态加入到队列的首端而不是末端！完美！

对于每次从队列中弹出的一个状态，我们还需要查看person是否就在box的四周且可以推动它。如果是的话，我们就推动盒子，从而得到新的状态(bx_new,by_new,bx,by)。易知```flag[bx_new][by_new][bx][by]=flag[bx][by][px][py]+1```。所以我们应该将这个新状态应该加入双端队列的末尾！

这种用双端队列来实现BFS的技巧，值得好好体会！


[Leetcode Link](https://leetcode.com/problems/minimum-moves-to-move-a-box-to-their-target-location)