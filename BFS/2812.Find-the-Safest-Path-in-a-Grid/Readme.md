### 2812.Find-the-Safest-Path-in-a-Grid

我们预先处理grid，通过多源BFS，求出每个格子到离其最近的thief的距离grid[i][j]。为了便于处理grid里已经存在数值为1的格子，在这里我们填充grid[i][j]表示该点"离最近的thief的距离+1".

然后我们二分搜值这个safety factor。假设是d，那么我们尝试寻找一条从左上到右下的通路，使得该路径不能包含有grid[i][j]<=d的格子，再走一次bfs即可判断。然后根据判断值，不断调整d的大小直至收敛。
