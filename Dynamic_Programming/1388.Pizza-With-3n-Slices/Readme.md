### 1388.Pizza-With-3n-Slices

此题的约束和```213.House-Robber-II```非常相似：1.永远不能取相邻的两个元素；2.首尾元素认为是相邻的（即不能同时取首尾两个元素）；3.此外本题还有一个条件，恰好取n/3个。

事实上，满足前述约束123的任何一种选取方案，都可以对应于一种本题里取pizza的方案。反之也是。严格的证明可以参考[这里](https://leetcode.cn/problems/pizza-with-3n-slices/solution/3n-kuai-pi-sa-by-leetcode-solution/)。

当然，我们这里可以简单用一个例子来验证一下。例如```100010101000```，有12个元素。其中三分之一（4个1）代表我们打算取的元素，它们是满足约束1,2,3的。我们先拿走最左边的1（随之删去左右相邻的两个零），原序列可以得到```001010100```，接下来```010100```，接下来```100```，最后恰好取光.

因此，本题就是House-Robber-II再加上取n/3个元素的条件。

对于处理首尾相接不能共存的问题，有着比较固定的解题套路：因为首尾不能共存，要么首元素不能取，要么尾元素不能取。前者就等效于考虑nums[1]~nums[n-1]的House Robber I，后者就是考虑nums[0]~nums[n-2]的House Robber I. 所以我们要做两道题，然后取较大的结果，即：
```
max( helper(0, n-2, n/3), helper(1,n-1,n/3) )
```

那么如何在helper函数里处理“取n/3个元素”的条件呢？那就是在dp状态上再加上一维。定义
```
f[t][i]: the maximum gain by the t-th round if we take i slices, AND for the t-th slice we do take it.
g[t][i]: the maximum gain by the t-th round if we take i slices, AND for the t-th slice we do NOT take it.
```
显然我们容易对照House Robber系列写出状态转移方程：
```
f[t][i] = g[t-1][i-1]+slices[t];
g[t][i] = max(f[t-1][i], g[t-1][i]);
```
和House Robber II对比一下，那道题不关心之前到底抢过几家，只关心总收益。而这里则需要加上“已经取的个数”的信息，因为这轮取了i个，说明之前一轮只能取i-1个，我们关心这个是因为最终总数不能超过n/3。
