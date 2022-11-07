### 2378.Choose-Edges-to-Maximize-Score-in-a-Tree

我们不难发现，如果从parent到node的edge被选中的话，那么node到它所有children的edge都不能选中。如果从parent到node的edge不被选中的话，那么node到它所有children的edge里只能最多选一条。

所以我们定义`dfs(node, 1)`表示从parent到node的edge被选中，那么以node为根的子树的最大收益。于是有
```cpp
dfs(node, 1) = sum{dfs(child, 0)};
```
同理，定义`dfs(node, 0)`表示从parent到node的edge不被选中，那么以node为根的子树的最大收益。因为我们允许有一条node的子边被选中，所以需要遍历这个选择。为了便于计算，我们先求出`Sum = sum{dfs(child, 0)}`，那么对于任何一个child，如果它的边被选中的话，则整棵树的最大收益就是`Sum - dfs(child, 0) + dfs(child, 1) + weight`. 我们遍历child，再返回最大的作为`dfs(node,1)`.

显然，此题需要记忆化来避免重复计算。
