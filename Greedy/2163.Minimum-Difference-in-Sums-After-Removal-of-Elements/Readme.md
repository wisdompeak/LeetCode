### 2163.Minimum-Difference-in-Sums-After-Removal-of-Elements

因为删除n个元素之后，剩余的2n个元素会自然地分成前后两个部分，所以我们很自然地会考察这两个部分的分界点在哪里。假设分界点在位置k，那么sum_first怎么选？自然就是nums[0:k]里面和最小的n个元素；sum_second怎么选？自然就是nums[k+1:n-1]里面和最大的n个元素。

于是问题转化为，如何高效地在前k个元素里找和最小的n个元素？显然我们就找最小的n个元素即可。从做往右遍历的时候，用一个优先队列始终保存n个最小的元素，就可以得到k左边最小的n个元素的和，记做leftMin[k]。同理我们可以用NlogN的时候，从右往左遍历，得到rightMax[k]，表示k右边最大的n个元素的和。

本题的答案就是找一个全局最小的```leftMin[k]-rightMax[k+1]```.
