### 124.Binary-Tree-Maximum-Path-Sum

任何一个max-sum-path必然会有唯一的一个最高节点，假设为node，我们就是遍历所有的node，找到每个node所能代表的max-sum-path，存下最大值。

对于一个node，其max-sum-path有这么几种情况：    
1. node->val
2. sum(node->left)+node->val
3. sum(node->right)+node->val
4. sum(node->left)+node->val+sum(node->right)   

其中sum(node)表示以node为最高点往下方向（不拐弯）的max-sum-path.

显然，我们可以构建DFS的sum函数。注意：
1. 它的返回值所对应的路径不要求拐弯，所以应该是 node->val, sum(node->left)+node->val, sum(node->right)+node->val 三者中的最大值。
2. 因为它会遍历所有的下层node，所以可以利用它在访问node时顺便把这个node所能代表的max-sum-path 最大值也更新了（就是按照上面规则四者中的最大值）


[Leetcode Link](https://leetcode.com/problems/binary-tree-maximum-path-sum)
