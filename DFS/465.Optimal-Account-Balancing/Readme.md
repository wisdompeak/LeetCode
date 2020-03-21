### 465.Optimal-Account-Balancing

首先，此题是NP-complete问题，只能用暴力的搜索．

我们比较容易想到的DFS方法是，对于第一个人净值不为零的话，我们找所有其他净值不为零的人匹配，将第一个人先填成零再说．然后递归处理剩下的．这种方法在lintcode上会超时．

另一种巧妙的方法是，其思想是：将这组人分成若干组，使得每组人的净值加和为零．这样总共Ｎ个人，如果能找到K个这样的组，那么实际交换的次数就是N-K．也就是每组内部每个人循环交换一次，而组间就不用交换了．所以如果能找到最大的分组数，那么总的最小的交换次数就是N-maxGroup

令一个Ｎ位的二进制数mask来记录每个人的状态．初始值mask=(1<<N)-1，其所有的bit位为一，表示这些人都还没有被考察.我们逐一遍历每种bit位的可能情况：
```cpp
for (int subset=mask; subset!=0; subset=(subset-1)&mask) 
```
如果遇到一个subset，其bit位为１的人的净值加和为零，那么我们就可以递归考察剩下的：
```cpp
if (zeroSum(subset)) DFS(mask-subset, groupCount+1);
```
递归的结束条件是mask变成了零，说明了所有的zero-sum subsequence已经遍历完了．


[Leetcode Link](https://leetcode.com/problems/optimal-account-balancing)