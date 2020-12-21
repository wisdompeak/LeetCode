### 435.Non-overlapping-Intervals

此题和452. Minimum Number of Arrows to Burst Balloons非常类似，都是利用一个排序解决问题．

将所有的区间按照右边界进行排序．

我们来到当前右边界最小（成为right）的那个区间，从排序后的interval中找到所有start小于当前这个右边界right的区间．这些区间都是可以删掉的！这是因为这些区间都互相重合，必然只能保留一个．而保留哪一个呢？就是保留当前这个右边界最小的区间，因为其他区间的右边界都较大，可能会造成对后面区间的重合，有潜在的风险，去掉他们最保险．

或者我们这样理解：为了保留更多的区间数目，在众多重合的区间里面，我们会优先选择右端点靠前的区间。因为它对后续的影响最小，有更大的概率让更多的区间出现。


[Leetcode Link](https://leetcode.com/problems/non-overlapping-intervals)
