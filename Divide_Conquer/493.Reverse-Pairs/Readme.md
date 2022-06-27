### 493.Reverse-Pairs

遇到这种题目，会发现如果这个数组是有序排列的，那么寻找pairs的过程就会方便很多。也就是说确定了i，很容易就能找到满足条件的j；反过来也是。这就强烈提示了需要用分治法（divide and conquer）来做，这是解决这类题型的套路。

分治法的最常见的应用就是与归并排序相结合。将数组对半划分为左右两部分，两部分各自是有序的；然后将两部分整体归并，在归并的过程中可以利用有序的性质解决一些问题。比如LeetCode的 493,315,327

另外，两个有序数组的归并排序操作，代码要熟练掌握。

补充：inplace_merge(iter1, iter2, iter3)可以实现[iter1,iter2)和[iter2,iter3)两段区间的归并排序（前提是两段各自有序）。

[Leetcode Link](https://leetcode.com/problems/reverse-pairs)
