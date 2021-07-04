### 1918.Kth-Smallest-Subarray-Sum

此题的二维版本就是```1439.Find-the-Kth-Smallest-Sum-of-a-Matrix-With-Sorted-Rows```.

我们用二分搜索猜测这个target。设计检验函数checkOK来判断if # of subarrays whose sum <= target is at least k. 如果是的话，那么这个target可以再小一些（但可能就是第k小的sum）；如果不是的话，说明target一定偏小，需要往大里猜。本题一定有解，所以收链解就是最终解。

在写checkOK(nums, target, k)的时候，用的是快慢指针。从左往右遍历慢指针i，然后调整快指针j使得sum[i:j]恰好大于target，于是j-i就是以i为左端点的合法subarray的数目（即subarray sum <= target）。然后我们将i移动一位，j继续单调地向右移动，同样直至恰好```sum[i:j]>target```，同样将j-i加入count里。一旦count的数目大于等于k了，就可以停止双指针的搜索了。
