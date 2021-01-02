### 435.Non-overlapping-Intervals

#### 解法1

此题和452. Minimum Number of Arrows to Burst Balloons非常类似，可以用贪心法来解决类似的区间问题。

我们之前总结过，对区间排序的贪心法，有的需要sort by starting point，有的需要sort by ending point. 大致的规律是：
1. 如果求的是maximum number of non-overlapping intervals，用sort by ending point的方法
2. 如果求的是minimum number of intervals to cover the whole range，用sort by starting point的方法

本题就是前者。我们把右边界最小（成为right）的那个区间做为首区间，从排序后的interval中找到所有start小于当前这个右边界right的区间．这些区间都是可以删掉的！这是因为这些区间都互相重合，必然只能保留一个．而保留哪一个呢？就是保留当前这个右边界最小的区间，因为其他区间的右边界都较大，可能会造成对后面区间的重合，有潜在的风险，去掉他们最保险．

或者我们这样理解：为了保留更多的区间数目，在众多重合的区间里面，我们会优先选择右端点靠前的区间。因为它对后续的影响最小，有更大的概率让更多的区间出现。

#### 解法2

因为我们求的是non-overlapping intervals，所以从左往右看每个区间的ending point，就是从右往左看每个区间的starting point。所以理论上本题也一定可以用sort by starting point来做。

当然，具体的做法与1不太一样。我们将所有的区间按照starting point排序之后，依次遍历它们。我们维护一个当前能到达的最远点far。如果
1. 新区间的左端点在far的右边，那么新区间就不会与之前的任何区间重合，计数器加1
2. 新区间的右端点在far的左边，那么新区间就被旧区间包围。我们于是舍弃之前的区间，而prefer当前的区间，并更新far为右端点，使其变得更靠前。目的是让后面有机会加入更多的区间。

[Leetcode Link](https://leetcode.com/problems/non-overlapping-intervals)
