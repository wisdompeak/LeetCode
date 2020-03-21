### 739.Daily-Temperatures

#### 解法1：贪心法
此题可以从后往前考虑．对于results[i]，我们考察其右边的那个元素，即```results[j],where j=i+1```. 

当temp[j]<=temp[i],我们将指针跳转j+=results[j]，这样就可以加快搜索的效率．这样直到找到一个temp[j]>temp[i]即为找到结果；或者直到发现results[j]==0时说明再也找不下去了．

#### 解法2：栈
此题可以非常类似于 maximum histgram，维护一个递减序列的栈，并且存放这的是index而不是数值。

此题可以从后往前遍历数组。此题转化为：对于任意的nums[i]，查找早于它处理的最近一个大于它的数的位置。于是这就是一个套路题。构造一个栈，维护一个递减数列：这样如果进入一个新数nums[i]小于栈顶元素，那么它的最近的大于nums[i]的数就是这个栈顶元素。如果这个新数nums[i]大于栈顶元素，就不断退栈直至遇到比它大的为止，那么当前这个栈顶元素也就是最近的一个比nums[i]大的数。因为存储的是index，所以很容易得到两个数在位置上的


[Leetcode Link](https://leetcode.com/problems/daily-temperatures)