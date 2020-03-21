### 975.Odd-Even-Jump

令dp_odd[i]表示从位置i开始作为奇数次的起跳，能否到达终点；dp_even[i]表示从位置i开始作为偶数次的起跳，能否到达终点。

从后往前考虑，对于元素A[i]，如果能寻找到它的下一步跳到的位置j，那么显然```dp_odd[i] = dp_even[j]```，```dp_even[i] = dp_odd[j]```.

怎么高效地从i找到j呢？对于奇数次跳跃，显然考虑将i之后的所有元素放在一起排个序，有就二分法```A[j] = *lower_bound(A[i])```，然后再从这个A[j]映射回j。同理，对于偶数次跳跃，也是考虑将i之后的所有元素放在一起排个序，有```A[j] = *prev(upper_bound(A[i]),1)```，然后再从这个A[j]映射回j。

显然，要保证所有i之后的元素放在一起是自动有序的，数据结构必然选择set或者map。这样每加入一个新元素，都是以log(n)的代价继续保持这个set或map是有序的。用lower_bound或upper_bound非常方便。


[Leetcode Link](https://leetcode.com/problems/odd-even-jump)