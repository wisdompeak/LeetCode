### 1918.Kth-Smallest-Subarray-Sum

此题本质等同于```719. Find K-th Smallest Pair Distance```. 在719中我们要寻找第k小的pair diff。在本题中，如果我们转成前缀和数组presum，那么本质上也就是在presum里找第k小的pair diff.

对于"k-th"的题型，二分搜值是一个固定的套路。我们假设第k小的diff的数值是mid，那么我们就计算presum里有多少diff<=mid的pairs。我们期望这个数量至少要是k个。如果count<k，那么我们对于diff的猜测太小了，包括mid在内的diff都不够k个，那么mid本身的diff怎么可能是第k个，所以我们必须往更大的数值猜（即left=mid+1）。如果count>=k，那么mid本身可能是正解（因为可能多有个diff的数值是mid），同时也可能我们猜的比较大，可以往更小的数值猜（即right=mid）.

那么我们如何在所有的diff里计算```countSmallerOrEqual(mid)```呢？两种思路：

1. 固定presum[i]，在presum里找多少个j，使得```presum[j]-presum[i]<=mid```，变化得到```presum[j]<=mid+presum[i]```，所以可以用upper_bound定位j的邻接位置j'。从```[i+1, j')```都是可行解。
2. 双指针。同样固定presum[i]，探索presum[j]。但是我们发现随着i的增大，j的临界位置也是单调变大的。所以j'可以用o(N)的算法找到。
