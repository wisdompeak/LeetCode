### 863.All-Nodes-Distance-K-in-Binary-Tree

#### 解法1：
本题的关键点是，任何两个节点AB之间的路径，都可以想象成有一个“拐点”O，其中OA是沿左子树向下的路径，OB是沿右子树向下的路径。我们可以递归处理每一个节点node，设想它是这个拐点，A是target并位于其中一个分支，那么如何在另一个分支中找到B？显然，假设我们能得到target到node->left之间的距离是t，那么我们只需要从node->right出发往下走k-2-t步，所抵达的节点就都是符合要求的B点。同理，如果target位于node->right分支，类似的处理。

需要单独处理的情况就是```node==target```，此时我们找的就是从node开始往下走k步到达的节点。

注意，```DFS(node)```函数的一个副产品就是可以返回target到达node的距离（假设target在node的下方），这样就可以避免再多写一个递归函数。

本题和```543.Diameter-of-Binary-Tree```的套路是一样的。也就是说，对于树里面任何两点之间的距离，优先去想它的拐点。

#### 解法2：
将树的形式转化为图的形式。这样就可以target为起点进行BFS，寻找距离为k的点。


[Leetcode Link](https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree)
