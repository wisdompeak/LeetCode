### 2313.Minimum-Flips-in-Binary-Tree-to-Get-Result

本题只要想到用tree dp来做，一切就迎刃而解。我们定义```dfs(node, expected)```表示为使得子树eval(node)的结果等于expected，所需要所做的最小修改。然后我们根据node的运算符和expcted的数值，分情况讨论：
1. 如果node是OR，且expcted是true，那么只要返回```dfs(node->left, 1)```或者```dfs(node->right, 1)```中的较小值.
2. 如果node是OR，且expcted是false，那么需要递归```dfs(node->left, 0)+dfs(node->right, 0)```.
3. 如果node是AND，且expcted是true，那么需要递归```dfs(node->left, 1)+dfs(node->right, 1)```.
4. 如果node是AND，且expcted是false，那么只要返回```dfs(node->left, 0)```或者```dfs(node->right, 0)```中的较小值.
5. 如果node是XOR，且expcted是true，那么只要返回```dfs(node->left, 0)+dfs(node->right, 1)```或者```dfs(node->left, 1)+dfs(node->right, 0)```中的较小值.
6. 如果node是XOR，且expcted是false，那么只要返回```dfs(node->left, 0)+dfs(node->right, 0)```或者```dfs(node->left, 1)+dfs(node->right, 1)```中的较小值.
7. 如果node是NOT，且expcted是true，那么需要递归```dfs(child, 0)```，其中child是node的唯一子树（左子树或者右子树）
8. 如果node是NOT，且expcted是false，那么需要递归```dfs(child, 1)```
9. 如果node是叶子节点，那么只需要返回```node->val != expected```

记得所有的结果需要记忆化，加快访问。
