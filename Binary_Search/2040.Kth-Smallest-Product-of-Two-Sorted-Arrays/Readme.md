### 2040.Kth-Smallest-Product-of-Two-Sorted-Arrays

本题是类似```1918.Kth-Smallest-Subarray-Sum```的套路题，采用二分搜值来猜测答案。

我们令```count = countSmallerOrEqual(m)```来计算有多少对乘积小于或等于m。如果这个数目小于k，那么说明m肯定不是答案，并且易知k太小，所以应该尝试更大的数（即lower = m+1）。如果count大于等于k，说明m可能是答案（因为允许有若干对成绩都等于m）或者m可能猜大了，所以接下来尝试更小的数（即upper = m）。利用二分搜值的模板，直至收敛到```left==right```，就是最终的解。

如果实现函数```countSmallerOrEqual(m)```呢？

#### 方法1：
最简单的方法就是遍历nums1[i]，在有序数组nums2里面用二分法找一个临界位置j，使得```nums1[i]*nums2[j]<=m```. 这个临界位置j的确定需要分类讨论。

如果nums1[i]>0，那么我们有```nums[j] <= m/nums1[i]```，当m/nums1[i]不能整除时，我们必须保守地取floor(). 这样我们可以用upper_bound求得第一个大于m/nums1[i]的位置j，那么[0,j-1]都是满足条件的解。

如果nums1[i]<0，那么根据不等式性质，移项需要变号，所以我们有```nums[j] >= m/nums1[i]```，当m/nums1[i]不能整除时，我们必须保守地取ceil(). 这样我们可以用lower_bound求得第一个大于等于m/nums1[i]的位置j，那么[j,n-1]都是满足条件的解。

特殊地nums1[i]==0，那么有多少j满足```0*nums[j]<=m```呢？这个其实取决于m。如果m是负数，无解。如果m是非负数，所有的nums2都是解。

#### 方法2：
类似1918，我们也可以用双指针的单调性来实现o(n)的```countSmallerOrEqual(m)```，不过讨论起来就更复杂了。

```nums1[i]* nums2[j] <= m```

1. m>=0    
(i) nums[i]>0：  我们有 nums2[j] <= m/nums1[i]。可以知道nums2[j]有个上界，且随着nums1[i]的增大，这个上界越来越小。所以我们从大到小单调地移动j，找到与i对应的临界位置j，那么[0:j]都是合法的解。   
(ii) nums[i]==0： 所有的nums2都是解。    
(iii) nums[i]<0：  我们有 nums2[j] >= m/nums1[i]。可以知道nums2[j]有个下界，且随着nums1[i]的增大，这个下界越来越小。所以我们从大到小单调地移动j，找到与i对应的临界位置j，那么[j:n-1]都是合法的解。   

2. m<0    
(i) nums[i]>0： 我们有 nums2[j] <= m/nums1[i]。可以知道nums2[j]有个上界，且随着nums1[i]的增大，这个上界越来越大。所以我们从小到大单调地移动j，找到与i对应的临界位置j，那么[0:j]都是合法的解。   
(ii) nums[i]==0： 所有的nums2都不会是解 （因为不可能 ```0*nums[j] < m```）。    
(iii) nums[i]<0： 我们有 nums2[j] >= m/nums1[i]。可以知道nums2[j]有个下界，且随着nums1[i]的增大，这个下界越来越大。所以我们从小到大单调地移动j，找到与i对应的临界位置j，那么[j:n-1]都是合法的解。   
