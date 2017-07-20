### 502.IPO

将project按照weight排序。每轮将所有小于当前W的projects都塞进一个pq里面，自动弹出利润最大的那个project。W更新后，之后再把小于当前的project入列。以此类推可以得到所需要的K个project。

需要注意的细节是：如果没有符合条件的K个project，该什么时候判断退出？（答案是在pq为空的时候）
