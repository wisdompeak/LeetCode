### 3013.Divide-an-Array-Into-Subarrays-With-Minimum-Cost-II

本题的本质就是从nums[1]开始，寻找一个长度为dist+1的滑窗，使得里面top k smallest的元素和最小。

对于求top k smallest，有常规的套路，就是用两个multiset。将滑窗内的top k smallest放入Set1，其余元素放入Set2. 

当滑窗移动时，需要加入进入的新元素k。我们需要考察是否能进入Set1（与尾元素比较）。如果能，那么需要将Set1的尾元素取出，放入Set2. 否则，将k放入Set2。

同理，当滑窗移动时，我们需要移除离开滑窗的旧元素k。我们考察k是否是Set1的元素。如果是，那么我们需要将Set1的k取出，同时将Set2的首元素加入进Set1里。

以上操作不断更新Set1的时候（加入元素和弹出元素），同时维护一个Set1元素的和变量sum，找到全局最小值即可。
