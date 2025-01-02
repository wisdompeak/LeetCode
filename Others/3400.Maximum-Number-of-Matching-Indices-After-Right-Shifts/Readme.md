### 3400.Maximum-Number-of-Matching-Indices-After-Right-Shifts

此题除了常规的n^2暴力枚举之外，还有一种更为巧妙的算法。我们定义长度为n的数组scores，其中scores[i]表示移动i次可以match到多少字符。

我们将nums2的所有元素存入一个hash表，key是元素大小，value是该元素出现的位置。然后遍历每个nums1[i]，我们通过hash表查看nums1[i]在nums2里出现的所有位置（比如说idx），那么我们就知道进行`(idx-i+n)%n`次shift的话，我们可以得到一个match，即给对应的score加上1分。

最终返回scores数字里的最大值。

这种算法的第二层循环不固定是n，因此效率会更高一些。
