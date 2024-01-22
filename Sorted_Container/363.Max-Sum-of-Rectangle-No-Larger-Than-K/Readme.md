### 363.Max-Sum-of-Rectangle-No-Larger-Than-K

Brutal Force的时间复杂度是o(m\*m\*n\*n)，肯定不明智。

一个很自然的想法是：选定任意两行之后，可以利用列方向上的累加和数组转化为一维的问题： max sum of subarray No larger than K，时间复杂度可以降为o(m\*m\*n\*logn)。

1.对于这个一维问题，首先构造横方向上的累加和数组sum，但注意累加和数组sum不会是单调增的，所以不能用数组的二分搜索！

2.然后，问题已经简化为对于一个数组sum，找到两个位置i和j，使其差不大于k。什么思路？
从前往后遍历j，搜索在j之前的元素是否有i满足条件 sum[j]-sum[i]<k，更新结果，并将j元素也加入累加和的序列中。

3.怎么样高效搜索j之前的sum元素呢？希望累加和元素的排练是有序的！但不能是数组，否则每次加入新元素并重排的耗时很长。快速保持有序序列的数据结构可以用顺序集合set，利用函数Set.lower\_bound(val)对其迭代器进行二分查找。注意，用 auto it = lower\_bound(Set.begin(),Set.end(),val) 虽然等价但会耗时非常长。
```cpp
                set<int>Set;
                Set.insert(0);
                int CurSum=0;
                for (int j=0; j<N; j++)
                {
                    CurSum+=sum[j];
                    
                    auto it = Set.lower_bound(CurSum-k); // 返回第一个大于等于CurSum-k的迭代器
                    if (it!=Set.end()) 
                        result = max(result,CurSum-*it);
                    Set.insert(CurSum);
                }
```

4.如果矩阵的行数远远大于列数，一定需要将矩阵转置以后再算，否则超时。


[Leetcode Link](https://leetcode.com/problems/max-sum-of-rectangle-no-larger-than-k)