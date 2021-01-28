### 1740.Find-Distance-in-a-Binary-Tree

解决Lowest Common Ancestor (LCA)的一个递归套路是：定义dfs(node, p, q)，返回值是一个pair，包含node与子节点p的距离、node与子节点q的距离。如果node下属没有子节点是p和q，那么对应的值是-1.

先分别递归```ans1 = dfs(node->left, p, q)```和```ans2 = dfs(node->left, p, q)```. 分情况讨论：
1. 如果ans1->first!=-1，那么说明node到p的距离是ans1->first+1
2. 如果ans2->first!=-1，那么说明node到p的距离是ans2->first+1
3. 如果node->val==p，那么说明node到p的距离是0
4. 其余的情况，node到p的距离标记为-1

同理，处理对于node到q的距离处理。

如果第一次出现node到p和q的距离都不是-1，那么node就是p和q的LCA。答案就是两距离之和。
