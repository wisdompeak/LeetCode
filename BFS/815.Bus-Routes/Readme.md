### 815.Bus-Routes

此题求最短的路径，可以尝试ＢＦＳ．有两种完全对称的思路．

第一种：因为题目问搭乘最少的route数目，我们可以尝试队列里放的就是routes.初始时，队列放S所连接的所有routes，然后对队列里的route查看它所到达的stop继而遍历这些stop可以继续延伸的routes．如果新的路线没有被访问过，就可以加入队列．结果是TLE．原因在于，从一个curRoute，考察所有的stop继而再考察所有延伸的nextRoute，这散开的规模非常大．

针对上面的算法，一个显而易见的改进就是，不仅考虑visitedRoutes，也需要考虑visitedStops，用两个集合来剪枝．这样可以勉强AC．之所以勉强，是因为在代码里我们需要先考虑的是ｖisitedStops，而一个stop所对应的route数量比较少，所以能对应节省的routes搜索比较有限．

第二种：我们考虑另外一种队列的结果，里面存放的不是route而是stop．初始时，队列里只有Ｓ．从起点开始，查看这个站点可以搭乘哪些routes，继而遍历这些routes可以继续到达的stops.同样，我们需要两个集合visitedRoutes和visitedStops来一起去重．这个算法和第一种算法完全对偶，但要比第一种快得多．这是因为代码里我们会先根据visitedRoutes来筛选，通常一条线路会有很多的stops,所以我们通过这个步骤先期筛除的stop会更多．


[Leetcode Link](https://leetcode.com/problems/bus-routes)