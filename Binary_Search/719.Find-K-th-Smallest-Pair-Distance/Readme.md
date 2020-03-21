### 719.Find-K-th-Smallest-Pair-Distance

对于能够明显判断出上下界的题目，用二分法的思想往往非常巧妙。

在本题中，将nums排序后，最大的差值是nums.back()-nums[0]；最小的差值必定存在于相邻的两个元素之间，也很容易算出来。于是相当于我们知道了差值的左边界left，右边界right，需要找一个居于中间的数mid，使得差值小于等于mid的pair数目正好是k个。

对于二分法的外框架，容易知道，需要二分搜索的次数就是 ```log_2^(right-left)```。对于给出的mid，如何得到差值小于等于mid的pair数目呢？也很简单，只要loop over 第一个数，那么第二个数的范围就可以通过upper_bound来确定。特别注意为什么是upper_bound.
```
for (int i=0; i<nums.size(); i++)
{
  auto pos=upper_bound(nums.begin(),nums.end(),nums[i]+mid); // 值大于nums[i]+mid的元素的指针
  count+= pos-1-(nums.begin()+i); // 值小于等于nums[i]+mid的元素的个数
}
```
用upper_bound()是 nlog(n)的复杂度。当然也可以通过双指针来做，就是o(n)的复杂度。

PS:对于求Kth smallest的题目，用binary search by value的方法往往能有奇效。相似的题目有：
```
668	Kth-Smallest-Number-in-Multiplication-Table
373	Find K Pairs with Smallest Sums
81	Search in Rotated Sorted Array II
4	Median of Two Sorted Arrays
```


[Leetcode Link](https://leetcode.com/problems/find-k-th-smallest-pair-distance)