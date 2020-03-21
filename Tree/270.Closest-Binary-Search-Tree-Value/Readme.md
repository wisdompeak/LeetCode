### 270.Closest-Binary-Search-Tree-Value
利用BST的性质不断朝target搜索，直至最底层。记录一路经过的根节点，不断更新 (root->val - target)的最小结果。

注意：result的初始值必须设置为root->val。


[Leetcode Link](https://leetcode.com/problems/closest-binary-search-tree-value)