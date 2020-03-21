### 1168.Optimize-Water-Distribution-in-a-Village

此题的解法非常巧妙。你增加一个隐藏的0号节点，把每个节点自建井的费用wells[i]想象成连接[0,i]的边的费用。这样，这道题就变成了求最少的费用将所有的节点（包括隐藏的0号）连接起来。这就是最基本的最小生成树问题（MST），和```1135.Connecting-Cities-With-Minimum-Cost```一模一样。


[Leetcode Link](https://leetcode.com/problems/optimize-water-distribution-in-a-village)