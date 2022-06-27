### 315.Count-of-Smaller-Numbers-After-Self

分治法的最常见的应用就是与归并排序相结合。将数组对半划分为左右两部分，两部分各自排序，然后将两部分整体归并，在归并的过程中就可以解决一些问题。比如LeetCode的 493,315,327

本题中带有鲜明的特征，即求nums[i]右边的所有小于它的数，这暗示了用分治和归并排序的算法。

在每一轮，序列start~end对半分为两部分，左序列区间从start到mid，右序列区间从mid+1到end。两个部分各自递归调用分治排序的函数后，都变得有序（存放在sortedNums里）。此时，对于左序列的任意nums[i]，都可以轻易在有序的右序列中用lower_bound找到可以插入的位置，也就知道了右序列中有多少小于它的数。据此可以更新count[i].

有人会问，那么在左序列中（从nums[start]到nums[mid]），肯定也有一些数小于nums[i]并且位于它右边呀。为什么不考虑呢？其实这部分在之前对于start~mid区间调用分治排序的函数处理过了。请仔细体会。

最后注意，本题需要三个数组，nums, sortedNums, count。原来的数据存在nums, 归并排序后的数组存在sortedNums, count[i]对应的是nums[i]的 number of smaller elements to the right.

补充：inplace_merge(iter1, iter2, iter3)可以实现[iter1,iter2)和[iter2,iter3)两段区间的归并排序（前提是两段各自有序）。


[Leetcode Link](https://leetcode.com/problems/count-of-smaller-numbers-after-self)
