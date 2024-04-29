### 3134.Find-the-Median-of-the-Uniqueness-Array

数组的subarray总数有`N = n(n-1)/2+n`个，直接求所有subarray的中位数肯定不现实。此题几乎肯定需要用二分搜值来解。

假设一个数字K，怎么判定它是否是所有subarray的distinct number的中位数，也就是第N/2个呢？显然，我们只需要判定`subarray with at most K distinct number`的个数是否有N/2个即可。有的话，我们就往小调整，否则就往大调整。

求“subarray with at most K distinct number”个数，可以用滑动窗口来解决。类似于340，992.
