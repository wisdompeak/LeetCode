### 1052.Grumpy-Bookstore-Owner

本题的意思是可以给你一个固定长度的滑窗，滑窗内的满意度可以累加（不管是否grumpy）。求某个滑窗位置时，整体满意度的最大值。

首先算出sum的基本盘，就是在没有滑窗覆盖的情况下，可以得到的满意度之和。

然后考虑一个长度为X的滑窗内，我们可能可以额外增加一些满意度。滑动窗口每一次移动，会加入一个元素customers[i]，考察它对应的grumpy[i]是否是1，是的话那就是额外增加的满意度，需要加入sum。同时也会有一个元素customers[i-X]离开滑窗，同样考察它对应的grumpy[i+X]是否是1，是的话我们就要退回额外的满意度，从sum中扣除。

整个滑动过程中出现的最大sum，就是答案。


[Leetcode Link](https://leetcode.com/problems/grumpy-bookstore-owner)
