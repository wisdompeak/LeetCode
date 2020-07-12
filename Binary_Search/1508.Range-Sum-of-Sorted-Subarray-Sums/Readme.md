###  1508.Range-Sum-of-Sorted-Subarray-Sums

暴力解法是将所有的subarray sum都计算出来。因此时间复杂度是o(N^2)。

如果当left和right的区间范围比较窄时，二分搜值的效率更高。我们设计```int kthSum(int k)```表示第k大的subarray sum。方法是：我们猜测某个sum值，检查nums数组里有多少个smaller or equal to sum的subarray。如果个数小于k，那么sum就要往大猜（即left=mid+1）；反之如果大于等于k，那么sum可能需要往小猜（即right=mid）。

```int kthSum(int k)```这个函数可以用快慢指针来实现，时间复杂度是o(N).

所以总体的时间复杂度是```(r-l)*n*log(Sum)```.

本题还可以有时间复杂度更低的```n*log(Sum)```的解法，思想是：假想所有的subarray sum排序的话，令totalSum2为前right个subarray sum的sum，totalSum1前left-1个subarray sum的sum。答案就是```totalSum2-totalSum1```.但是写起来比较复杂。主要原因是：可能有重复的subarray sum都与第left个subarray sum的数值相同。同理，第right个subarray sum两边也会有若干个相同的值。
