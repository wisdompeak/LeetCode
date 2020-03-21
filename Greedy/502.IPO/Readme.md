### 502.IPO

将所有项目按照capital排序。在1\~k轮中，每轮将所有capital小于当前W的项目都塞进一个pq里面，自动弹出利润最大的那个项目。就是当前的最优解。

W更新后，之后再把capital小于当前W的项目入列。以此类推可以得到所需要的K个项目。

需要注意的细节是：如果没有符合条件的K个项目，该什么时候判断退出？（答案是在pq为空的时候）


[Leetcode Link](https://leetcode.com/problems/ipo)