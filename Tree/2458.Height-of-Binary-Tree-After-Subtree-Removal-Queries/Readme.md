### 2458.Height-of-Binary-Tree-After-Subtree-Removal-Queries

我们定义一个节点的height表示从它到叶子节点的最大距离，depth表示从它到root的距离。

我们移除node节点对应的子树后，剩下的树的高度其实就取决于与它同depth的节点的height。所以我们将所有处在同depth的节点的height都提前收集好，那么就很容易找到其他子树的最大height。

特别注意，如果某个深度的节点只有一个，那么将其移除后，剩下树的最大高度就是该节点的depth-1.
