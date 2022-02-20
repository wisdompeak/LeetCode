### 2179.Count-Good-Triplets-in-an-Array

本题的入手思路如下。我们容易确定相同数字在两个数组中的位置，类似nums1[i]==nums2[j]
```
X X X i X X X X X X X 
X X X X X X j X X X X
```
自然地，我们希望知道有多少```x>i```和```y>j```，使得nums1[x]==nums2[y]. 比较暴力的方法是遍历大于i的所有位置x，查看nums[j+1:n-1]区间内是否有与nums1[x]相同的数。但从这个算法来看并没有优化的空间，因为能有多少配对完全是随机事件。如何更高效地去做呢？

考虑到所有的元素都互不相同，这里有一个技巧：因为我们对nums1里面的元素大小并不关心，我们其实可以只看编号不看数值，这样nums1在我们眼里可以就只是```0,1,2,3...,```，这样就构建了一个映射。将nums1所做的映射也应用在nums2里面，则nums2重新变换成了一个新的乱序排列。这里就发现了规律，变换后nums1里面在i后面的元素，意味着在nums2里面必然都比nums[j]的数值大。反过来说，nums2里那些比nums2[j]大的数，意味着在nums1里时一定排在i后面。所以我们需要根据nums2[j]计算一个新数组largerAfterSelf[j]，表示nums2[j]后面有多少元素比自己大，那么这些元素必然也存在于nums1[i]的后面。

同理，我们可以构造smallerBeforeSelf[j]，表示nums2[j]前面有多少元素比自己小，那么这些元素必然也存在于nums1[i]的后面。

最终的答案就是```sum{smallerBeforeSelf[j] * largerAfterSelf[j]}, for i=0,1,2,..,n-1```. 这个思路在```1713.Minimum-Operations-to-Make-a-Subsequence```里也有应用。

计算largerAfterSelf的方法同```315.Count-of-Smaller-Numbers-After-Self```，可以用分治+归并排序，也可以套用树状数组。

对于BIT的解法，我们注意到所有数值的大小不超过1e5，所以开辟长度为1e5的树状数组作为篮子，每考察nums[i]，就需要在树状数组的[nums[i]+1: INT_MAX]区间内累加所有的数据之和，这个就是largerAfterSelf[i]. 之后记得在idex = nums[i]的位置自增1. 
