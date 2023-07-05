### 2753.Count-Houses-in-a-Circular-Street-II

我们先找到一处状态为open的门。然后从下一个位置作为起点，连续走k格，图中如果遇到任何open的门就将其关闭，但同时记录并保持更新lastOpen相对于起点的距离。

走完k格之后，lastOpen一定就是起点之前的那扇门，于是lastOpen相对于起点的距离就是整圈的长度。
