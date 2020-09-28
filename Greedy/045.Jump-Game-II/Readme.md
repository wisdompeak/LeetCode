### 45.Jump-Game-II

求最少步数到达目的地的算法，最常见的就是BFS。本题可以仿照其思想。

第0步所能到达的点就是0. 第一步所能到的点的右边界就是0+nums[0]，也就是说第一步跨越的范围就是[1, 0+nums[0]。那么第二步所能到达的范围是什么呢？最小的位置，应该是第一步所能达到的最远点的下一个位置；最大的位置，应该是第一步所能达到的所有的点所共同更新的最远边界。

所以我们可以类似BFS的层级遍历，每走一步，弹出旧的元素区间[start,end]，然后装入新的元素区间[start_new, end_new]。
```
start_new = end+1; 
end_new = max{i+nums[i]} for i=[start,end]
```
每一步只要start<=end，就可以认为队列里还有元素，BFS就能继续。直至end_new到达最末的位置，或者start>end。

[Leetcode Link](https://leetcode.com/problems/jump-game-ii)
