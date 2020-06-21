### 124.Binary-Tree-Maximum-Path-Sum

任何一个max-sum-path必然会有唯一的一个最高节点（或者看作是拐点）。我们的基本思想就是遍历所有的node，计算它作为拐点所能取到的max-sum-path。然后用一个全局变量做实时的更新。

对于以node作为拐点的maxTurnSum，肯定包括了自己本身。那么往node的左节点再往下能走多远呢？其实取决于```maxDownSum(node->left)```。maxDownSum的意思是从起点出发往下“不拐弯”所能得到的最大路径和。如果```maxDownSum(node->left)>0```，那么maxTurnSum肯定会选择往左边继续往下，否则maxTurnSum就不会有左边的支路。对于右子树的分析同理。

所以我们有这样的表达式：
```
maxTurnSum(node) = node->val + max(0, maxDownSum(node->left)) + max(0, maxDownSum(node->right))
```

显然，我们真正需要写的递归函数应该是maxDownSum(node)：

1. 它的返回值所对应的是不要求拐弯的最大权重路径，所以 ```maxDownSum(node) = node->val + max(maxDownSum(node), maxDownSum(node->right)```。
2. 因为这个递归函数会遍历所有的node，所以利用访问node的机会，顺便计算maxTurnSum(node)，注意这个才是最终答案所需要的。


[Leetcode Link](https://leetcode.com/problems/binary-tree-maximum-path-sum)
