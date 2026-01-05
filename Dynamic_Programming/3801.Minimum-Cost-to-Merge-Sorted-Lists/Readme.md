### 3801.Minimum-Cost-to-Merge-Sorted-Lists

因为数组的数量很少（不超过12），显然是可以用状态压缩来穷举所有组合。因此本题就是一个利用bit mask来进行组合标记的区间型DP。

对于任意组合mask而言，它的前驱状态是两个互斥子集的合并。所以我们可以遍历它的subset（自然就得到了另一半`other=mask-subset`）。于是容易有状态转移方程：
```cpp
dp[mask] = max{dp[subset] + dp[other] + len[subset] + len[other] + abs(median[subset]-median[other])}  for all subsets
```
对于每个mask而言，它对应的合并数组的长度容易计算，记作L。那么它的中位数呢？考虑到mask对应的每个数组都是有序的，我们可以用二分搜值的方法找到这个mask对应的合并数组的第(L+1)/2个元素。具体的方法：我们猜测一个数值v，如果mask对应的数组里所有小于等于v的个数少于(L+1)/2个，那么v一定不是解，故需要将猜测的下界提升至v+1，否则我们可以将猜测的上界将至v。直至我们收敛出唯一解，就是第(L+1)/2个元素。
