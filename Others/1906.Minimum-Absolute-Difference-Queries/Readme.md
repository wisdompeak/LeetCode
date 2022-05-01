### 1906.Minimum-Absolute-Difference-Queries

本题正面硬刚是很难做的。突破口在于nums的数值大小只有100. 意味着我们可以遍历这个数值。也就是说，对于一个nums的一个子区间，我们可以试图遍历它包含了多少个1，多少个2，多少个3，直至多少个100. 那么如果计算一个区间内某个元素的频次呢？可以用线段树，但是前缀和显然更简单。

我们提前预处理得到presum[k][i]，表示nums[0:i]这个前缀数组里包含了多少个数值k。显然，对于[left,right]的query，里面含有k的数目就是presum[k][right]-presum[k][left-1]. 我们将[left,right]内包含的所有数值（即presum之差大于零）排个序，找邻接最小的gap。
