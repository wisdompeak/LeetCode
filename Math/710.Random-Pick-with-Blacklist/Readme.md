### 710.Random-Pick-with-Blacklist

#### 解法1：
显然，N个元素，刨去黑名单中的元素，剩下M个元素。我们每次生成的随机数就是在0~M-1之间。问题就是，如果随机数是k，但是k在黑名单里，该怎么办？

我们用映射的思想，将处于[0,M)但也是黑名单里的数，映射为[0,M)之外的合法数字。这个在预处理的时候就可以实现。只要从N-1里降序遍历，只要不在黑名单里的数字，都逐次用来填充黑名单。

#### 解法2：
有一个比较骚气的binary search的解法，虽然时间效率不是很高，但是角度很新颖。

我们二分搜索一个位置pos，计算count等于[0,pos]的区间里面有多少个合法的数。然后不断缩小规模，直至找到最小的一个位置，使得count恰好等于k（k就是随机数，表示我们需要取第k个合法的数）。最终二分搜索收敛后的这个位置就是答案。

然后我们考虑count怎么写。count其实就是pos+1-[0,pos]里面有多少个黑名单的数。那么对于给定的区间[0,pos]。如何计算有多少在黑名单里呢？同样我们先将黑名单排序，然后查看pos在黑名单的位置。更具体的，我们需要找到的是blacklist.upper_bound(pos)的迭代器iter（即第一个大于pos的位置），显然从blacklist.begin()到prev(iter,1)都是小于等于pos的黑名单成员，因此这个[0,pos]区间内黑名单的数目就是iter-blacklist.begin().


[Leetcode Link](https://leetcode.com/problems/random-pick-with-blacklist)