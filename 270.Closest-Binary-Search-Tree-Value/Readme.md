### 270.Closest-Binary-Search-Tree-Value
利用BST的性质不断朝target搜索，直至最底层。记录一路经过的根节点，不断更新 (root->val - target)的最小结果。
