### 337.House-Robber-III

此题和其他House Robber系列不同，House的排列不是序列的数组，并不适合DP算法．这是因为left的最佳策略，不仅取决于它的上级parent的策略，而且还要取决于right的策略．动态转移方程很难确定．

如果用常规的DFS就很简单明了．每一个node的策略(rob or not)都尝试一遍并向下延伸，最终取两者之间的最优．

注意的是，肯定会有很多重复搜索的情况．比如说节点A取rob并向下dfs的过程中，后续的节点Ｂ需要考察rob的决策；而Ａ取not rob并向下dfs的过程中，后续的B可能也需要考察rob的决策．所以需要记忆化，将每个节点的决策及其价值都记录下来．


[Leetcode Link](https://leetcode.com/problems/house-robber-iii)