### 354. Russian-Doll-Envelopes

#### 解法1：
我们将所有的信封按照长度从小到大排序之后，符合要求的信封嵌套序列一定是这个排序数组的一个subsequence（否则无法满足长度的递增要求）。

我们可以用N^2的DP方法，在这个数组中找到宽度的最长递增子序列(LIS)。参考```300. Longest Increasing Subsequence```. 注意对于第i个元素，想寻找它在LIS中的前一个元素j，必须同时满足两个条件：
```width[j]<width[i] && length[j]<length[i]```。否则会将长度相等、宽度不等的两个信封选入同一个LIS中。

#### 解法2：
本题有一个技巧可以在求LIS的过程中不用再考虑长度的制约。那就是排序的时候，将长度相同的信封按照宽度降序排列。这样的好处是，相同长度的信封，不可能在宽度上是递增的。这样求宽度的LIS时，不可能选到两个长度相同的信封。于是，单纯求解宽度数组的LIS序列，就可以用o(NlogN)的贪心解法了。参考```300. Longest Increasing Subsequence```. 

[Leetcode Link](https://leetcode.com/problems/russian-doll-envelopes)
