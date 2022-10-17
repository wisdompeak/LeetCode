### 2444.Count-Subarrays-With-Fixed-Bounds

本题的关键是掌握好“数subarray”的诀窍。我们通常都是固定一个端点，查看另一个端点可以在哪些地方。

我们考虑如果这个subarray的右边是nums[i]，那么这个subarray的左端点之后必须包含至少一个minK和maxK。所以我们只要知道i左边最近的minK和maxK，取两者的较小值j，那么[j:i]就是以i结尾的、最短的符合条件的subarray。左端点从j往左延伸的话，这个subarray依然有效。但是特别注意，左端点不能延伸到非法的区域，即小于minK或者大于maxK的地方，所以实际左端点移动的范围是j-boundary，其中boundary是i之前最近的非法位置。
