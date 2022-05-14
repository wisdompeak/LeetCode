### 056.Merge-Intervals

对于区间合并的题目，一般都会采用和252类似的“扫描线”算法。对于每一个区间[a,b]，我们在a时刻记录+1，在b时刻记录-1. 然后我们再在时间轴上顺次遍历每一个时间点，统计这些+1和-1的总和。我们会发现当sum从0变为正数时，意味着一个merged interval的开始；当sum从正数变成0时，意味着一个merged interval的结束。这样就巧妙地把所有存在overlap的区间都合并到了一起。

需要注意的是，对于相同的时刻，如果同时存在多个+1或者-1，应该先处理+1后处理-１。比如[a,b]和[b,c]两个区间，在处理b时刻时，按照先+1再-1的顺序，就不会出现sum=0的情况了，也就避免了merged interval在b处断开。


[Leetcode Link](https://leetcode.com/problems/merge-intervals)
