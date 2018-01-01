### 300.Longest-Increasing-Subsequence
贪心算法中的经典题：求最长子序列。

遍历所有元素，维护一个递增的数组q：当q为空，或者新元素val大于q.back()时加入q尾；否则，寻找q中第一个适合val插入的位置（原q序列里第一个大于等于val的位置），替换成val。 

如此遍历结束之后，q.size()就是最长子序列的长度。

对于C++，用lower_bound(q.begin(),q.end(),val)返回的就是第一个大于或等于val的元素的迭代器（或者说是地址）。
