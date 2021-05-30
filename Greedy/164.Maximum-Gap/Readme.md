### 164.Maximum-Gap

假设有N个元素A到B。

那么可以推算，相邻元素的maxumum gap不会小于(B - A) / (N - 1)，否则无法达到B-A的跨越。

所以令bucket（桶）的大小 bucket_size = (B - A) / (N - 1)，则最多会有 bucket_nums = (B - A) / bucket_size + 1个桶。

对于数组中的任意整数nums[i]，很容易通过算式 idx = (nums[i] - A) / bucket_nums 找出其桶的位置，然后维护每一个桶的最大值和最小值。

由于前面提到，maximum gap不会小于bucket_size，而同一个桶里的元素的差值最多是bucket_size-1，因此最终答案所对应的两个数不会来自同一个桶中。

对于每一个非空的桶p，找出下一个非空的桶q，则q.min - p.max可能就是备选答案。返回所有这些可能值中的最大值。


[Leetcode Link](https://leetcode.com/problems/maximum-gap)
