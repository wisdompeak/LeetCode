### 473.Matchsticks-to-Square

本题是NP-hard的搜索题，基本思想就是无脑的DFS,挨个尝试所有的nums元素的组合,是否能恰好构成四段大小相等的sum(这个sum就是nums总数和的四分之一).

本题设计的递归函数: ```bool DFS(vector<int>& nums, int curIdx, int curEdge, int curSum, vector<int>& visited)```

curEdge表示当前我们在凑第几条边.如果凑满四条边,就说明成功.

curSum表示对于当前的边,我们已经累加了多少数字.如果累加到恰好curSum==sum,那么我们就清零开始DFS下一条边.如果curSum>sum,就可以终止当前搜索.如果curSum<sum,则当前边还需要尝试搜索更多数字加入进去.

visited是标记每个数字是否被访问过.因为是整体就是深度搜索+回溯的算法,所以要记得退出时要恢复标记.

另外，一个常用的节省时间的技巧是将nums按照从大到小排序，这样能更容易遇到不合条件的情况，及早剪枝，避免过深的探索。

LC上有一道几乎一模一样的题目：698. Partition to K Equal Sum Subsets


[Leetcode Link](https://leetcode.com/problems/matchsticks-to-square)