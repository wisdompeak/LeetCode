### 435.Non-overlapping-Intervals

此题和452. Minimum Number of Arrows to Burst Balloons非常类似，可以用贪心法来解决类似的区间问题。

我们之前总结过，对区间排序的贪心法，有的需要sort by starting point，有的需要sort by ending point. 大致的规律是：
1. 如果求的是maximum number of non-overlapping intervals，用sort by ending point的方法
2. 如果求的是minimum number of intervals to cover the whole range，用sort by starting point的方法

本题就是前者。我们把右边界最小（成为right）的那个区间做为首区间，从排序后的interval中找到所有start小于当前这个右边界right的区间．这些区间都是可以删掉的！这是因为这些区间都互相重合，必然只能保留一个．而保留哪一个呢？就是保留当前这个右边界最小的区间，因为其他区间的右边界都较大，可能会造成对后面区间的重合，有潜在的风险，去掉他们最保险．

或者我们这样理解：为了保留更多的区间数目，在众多重合的区间里面，我们会优先选择右端点靠前的区间。因为它对后续的影响最小，有更大的概率让更多的区间出现。


[Leetcode Link](https://leetcode.com/problems/non-overlapping-intervals)
