### 1124.Longest-Well-Performing-Interval

如果我们将所有的tiring day标记成为1，non-tiring day标记成为-1，那么题意就是说，在一个1和-1组成的数组里找一个最长的区间[i,j]，使得区间里面1的个数要多于-1的个数。

如果我们继续转换一下这个数组变成前缀和数组presum，可以发现presum[i]表示的就是从第0天截止到第i天为止，tiring day与non-tiring day相比的数目之差。于是题意就转化成了：在这个presum数组里，找一对距离最远的pair(i,j)，使得presum[i-1] < presum[j]（这样就表示从区间[i,j]里tiring day与non-tiring day相比的数目之差是正数，符合题意）。

于是这道题就变得和 962. Maximum Width Ramp 一样了，可以用单调栈的技巧在o(n)时间解决。

事实上，这道题抽象起来就是求：任意数组A里最宽的一对pair(i,j)，使得 A[i]<A[j]（或者A[i]>A[j]），我们可以称之为“farthest greater element”。这和之前常做到的“next greater element”是恰好相反的题意。这两题都是可以用单调性完美地解决的。


[Leetcode Link](https://leetcode.com/problems/longest-well-performing-interval)