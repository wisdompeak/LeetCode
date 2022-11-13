### 2467.Most-Profitable-Path-in-a-Tree

两次遍历全树。第一次遍历求得每个点到bob所在节点的距离（但只限bob节点往上的部分）。第二次遍历求每个点与root的距离。

对于每个节点而言，如果前者大于后者，则对于Alice而言没有收益。如果前者小于后者，则Alice可以拿取该节点的价值。基于这个原则，第二次dfs的时候可以求得收益最大的一条从root到leaf的路径。

通过本题，需要掌握不需要建rooted tree的dfs方法，即`dfs(cur, parent)`。当`next[cur]!=parent`时，可以继续递归`dfs(next[cur], cur)`。
