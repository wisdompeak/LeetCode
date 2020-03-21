### 1024.Video-Stitching

此题非常类似 45.Jump Game II，整体就是一个贪心的策略。略微的差异就是我们需要预先将这些clips排序，排序的原则就是左端点靠前的优先，其次右端点靠后的优先。

我们从第一个区间[0,right]开始考虑，将之后所有左端点位于right之前的clips都查看一遍（意味着与之前的区间有overlap），考察他们各自的右端点，取最大值得到能够推进到最远的位置farReach。这对应增加一个clip的操作（这个clip的右端点就是farReach）。然后更新right=farReach，再重复之前的操作，直到抵达target。

特别注意，如果更新farReach之后仍然等于right，就意味着没有其他clip与当前的区间能够overlap，应该及时返回-1，否则会死循环。


[Leetcode Link](https://leetcode.com/problems/video-stitching)