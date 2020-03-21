### 484.Find-Permutation

需要人工分析出最优的策略。

以“下拐点”为分界点将s序列分为若干个II...IIDD...DD的组合。对于每个II...IIDD...DD，可以知道最优方法是：将除最后一个I之外的所有I对应一个递增数列，剩下的一个I和所有的D对应一个递减数列，且递减数列的最小值是那个递增数列最大值加1。更有用的是，可以知道，所有的递增数列的值都是和它的index值是对应的`results[i]=i+1`。

那么s的位数和results的位数不一样怎么办？一个简单的方法是`s.insert(s.begin(),s[0])`，这样s和results的元素数目就是一致的，且各个位置都适用同样的代码语句。


[Leetcode Link](https://leetcode.com/problems/find-permutation)