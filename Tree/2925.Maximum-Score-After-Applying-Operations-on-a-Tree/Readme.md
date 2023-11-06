### 2925.Maximum-Score-After-Applying-Operations-on-a-Tree

我们令dfs(cur)表示以cur为根的子树保持healthy时，能够取得的最高分。

我们容易发现，从root一路往下时，只要在某个节点node采取了“不取”的策略，那么之后就没有继续往下走的必要了。因为从root到node再到它的任何一个leaf，这个path sum肯定不会是零。所以我们必然会贪心地将node以下所有节点的value都取走。

所以我们在dfs的过程中，如果遍历到了某个节点，其隐含的意思就是从root到node之间的路径都“扫荡”光了。此时如果node依然采用了“取”的策略，那么我们必须保证node的所有子树path都是healthy的才行。于是就是递归处理dfs(nxt)即可。

边界条件是对于leaf node，它必须不取，否则连它也取的话，则意味着从root到leaf的path每个节点都取光了，必然不是healthy。
