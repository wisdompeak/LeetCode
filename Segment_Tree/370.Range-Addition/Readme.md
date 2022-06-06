### 370.Range-Addition

#### 解法1：差分数组
此题比较简单的解法是用差分数组```diff```。```diff[i]```表示```nums[i]```比```nums[i-1]```大多少。这样如果已知```nums[i-1]```，那么就有```diff[i]=nums[i-1]+diff[i]```。本题中的三元参数```update(i,j,k)```恰好就是给出了这样的差分数组的信息：```diff[i]+=k, diff[j+1]-=k```.

#### 解法2：线段树
本题和307很相似，也可以用线段树来实现。最大的区别就是本题中需要实现的是区间更新。在线段树的basic版本中（LC307），我们实现的都是单点更新，用单点更新来实现区间更细，效率肯定很低。

本题实现的是线段树的进阶版本，使用lazy tag来实现区间更新的延迟推广。具体的说，我们想要将区间[a:b]增加1时，不一定需要立即下沉到每个叶子节点将其info增1。如果我们没有对[a:b]中的任何一个叶子节点做查询的话，意味着不需要任何下沉操作。我们只增加[a:b]对应的节点的info，但同时标记该节点的tag为1。如果以后某个时刻，我们需要下沉访问某个下层区间或者叶子节点，那么在下沉的过程中必然会重新经过[a:b]对应的node，此时我们顺便将tag信息读入并在访问下层区间或叶子节点时，将它们的info加上这个“延迟加载”的1就行。

这个版本的线段树有如下API：

初始化：```void init(SegTreeNode* node, int a, int b)```，其意义是对以node为根节点的线段树进行节点的赋值，在其下面构造b-a+1个叶子节点，每个节点（id）对应的元素值从全局变量nums[id]里面读取和写入。显然，这种写法下，初始化只要一步：init(root, 0, n-1).

区间更新：```void updateRangeBy(SegTreeNode* node, int a, int b, int val)```，其意义是对以node为根节点的线段树，在下面更新所有nums[a:b]所对应的节点，使其info都increase by val.注意，这和LC307基础版本的区别，val是增量。

区间查询：```int queryRange(SegTreeNode* node, int a, int b)```，其意义是对以node为根节点的线段树，在下面更新所有nums[a:b]所对应的节点的info之和。


[Leetcode Link](https://leetcode.com/problems/range-addition)
