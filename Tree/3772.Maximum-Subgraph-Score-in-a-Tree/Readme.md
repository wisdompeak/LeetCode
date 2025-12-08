### 3772.Maximum-Subgraph-Score-in-a-Tree

我们必然会逐个节点地考察subgraph。可以发现对于一个node而言，它所在的subgraph可以分为两部分：以node <-> parent这条edge做切割，一部分是以node为根的子树部分，另一部分是以parent往外发散的部分（可以看做是以parent为根的子树）。

对于前者，典型的子树递归，这显然是可以用dfs求解的。我们令dfs1(cur)表示以cur出发往下发展，在其为根的子树里得分最大的subgraph。显然有
```
dfs1(cur) = score[cur] + sum{max(0, dfs1(child)} over all children.
```
对于后者，我们就需要用到移根的策略进行递归。我们令dfs2(cur)表示从cur往上走能得到最大score的subgraph（可看做以parent为根的另一半子树），并将最大得分记作dp2[cur]。我们考察cur的一个child、对于dp2[child]而言，它在几何上包括两部分：cur子树里去掉child分支的subgraph（即dp1[cur]-dp1[child]），以及更靠外的dp2[cur]. 所以有两者的移根关系
```
dfs2(child) = max(0, max(0, dp1[cur]-dp1[child]) + dp2[cur]);
```
这里面dfs2需要注意两个细节。

首先dp1[cur]可能本来就不包括child分支（如果当child分支可能是负数时），所以我们在算cur为根、但除child分支之外的subgraph时，应该用 max(0, dp1[cur]-dp1[child]).

其次dp2[child]不能为负数。即如果从cur往上走的subgraph最大值依然为负数，那么索性dp2[child]的贡献应该降为零。

最终每个node所能扩展的subgraph构成的最大值就是dp1[node]+dp2[node].
