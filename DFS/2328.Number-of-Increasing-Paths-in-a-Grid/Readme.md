### 2328.Number-of-Increasing-Paths-in-a-Grid

#### 解法1：动态规划
考虑到所有元素的数目只有1e5，那么我们可以将其按照从小到大排序。然后依次访问这些元素(i,j)，查看它四周的格子(x,y)是否有比它小的。是的话，就有```dp[i][j]+=dp[x][y]```，其中dp[i][j]表示以其为结尾的、符合条件的严格递增序列的数目。特别注意，(i,j)本身也可以是一个单元素的序列，所以dp[i][j]要加上1.

最终的答案是将所有dp[i][j]加起来。因为符合条件的严格递增序列可以以任何位置结尾。

#### 解法2：DFS
事实上本题不需要排序。我们只需要DFS和记忆化搜索。我们令dfs(i,j)表示以(i,j)为起点的递增序列的个数。我们可以从任意一个位置(i,j)出发，寻找四周比其大的格子(x,y)，然后递归调用dfs(x,y)，将其结果再加在dfs(i,j)上即可。本题需要记忆化dfs的结果来避免重复调用。


此题和[329.Longest-Increasing-Path-in-a-Matrix](https://github.com/wisdompeak/LeetCode/tree/master/DFS/329.Longest-Increasing-Path-in-a-Matrix)非常类似。
