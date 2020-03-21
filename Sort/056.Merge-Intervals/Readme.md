### 056.Merge-Intervals

和２５２类似的解题手法．

需要注意的是，此题中的有效区间长度可以为0，即[t,t]也是合法的，所以在数组ｑ中，我们除了按时间排序之外，第二指标应该按照先1后-１的次序．即如果遇到相同的时刻，{start，1}要比{end,-1}先进行处理，这样就能顺利地包容[t,t]这样的区间．


[Leetcode Link](https://leetcode.com/problems/merge-intervals)