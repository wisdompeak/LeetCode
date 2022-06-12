### 2302.Count-Subarrays-With-Score-Less-Than-K

根据```Count Subarrays by Element```的套路，我们不会用o(N^2)遍历数组。我们会尝试用o(N)遍历每个元素，考察它unique地对应了哪些数组。

因为这道题里的subarray并没有任何代表其特征的最大值、最小值之类的，所以我们可以考虑将每种subarray的最后一个元素作为代表。具体的说，如果nums[i]是符合条件的subarray的最后一个元素，那么这个subarray的起点可以在哪里？显然，长度越长，起点越靠前，权重和就越大，直至可能超过k。利用单调性，我们就能用二分搜索来确定该subarray的最大长度，即对应了有多少个符合条件的subarray。
