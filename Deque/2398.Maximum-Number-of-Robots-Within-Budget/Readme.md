### 2398.Maximum-Number-of-Robots-Within-Budget

很明显，budget越多，能够跑的机器就越多，这是一个单调的过程。所以我们用二分法来试探最大的机器数目。

如果确定了一个长度，我们就跑一遍滑窗，需要计算每个时刻滑窗内的元素之和与元素最大值。显然，用单调deque是解sliding window maximum的固定套路，时间复杂度是o(n)。

此题如果用一个有序容器（比如说multiset），结果会超时。另外，用线段树也是一个可行的选择。
