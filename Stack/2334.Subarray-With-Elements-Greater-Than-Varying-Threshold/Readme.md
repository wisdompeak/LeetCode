### 2334.Subarray-With-Elements-Greater-Than-Varying-Threshold

这道题的套路隐藏地非常巧妙。如果我们将nums看成一个histogram，那么本质就是求一个rectange，其面积要大于threshold。

于是这就完全转化成了`84-Largest-Rectangle-in-Histogram`，我们只要遍历每个元素，考察它作为矩形的高时，宽的最大范围，再查看area是否大于threshold即可。
