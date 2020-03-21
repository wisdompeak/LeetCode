### 581.shortest-unsorted-continuous-subarray

本题的难点是如何设计不需要排序的o(n)算法。

找出这样一个right_bound：位于该数左边的所有数的最大值，要比这个数大，这说明这个数在排序后需要变换位置。怎么找呢？将数组从左到右过一遍，实时保存最大值即可，不断刷新这个right_bound。

同理，找到这样一个left_bound：位于该数右边的所有数的最小值，要比这个数小，这说明这个数在排序后需要变换位置。也是讲数组从右往左过一遍，实时保存最小值。

最后当right_bound>left_bound时，结果就是 right_bound-left_bound+1


[Leetcode Link](https://leetcode.com/problems/shortest-unsorted-continuous-subarray)