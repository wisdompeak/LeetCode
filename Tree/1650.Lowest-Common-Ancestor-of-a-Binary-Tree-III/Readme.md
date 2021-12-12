### 1650.Lowest-Common-Ancestor-of-a Binary-Tree-III

本题既然给出了每个节点的parent，那么只要把p和q上行至root的路径都遍历出来，然后分别反向。这样两条路径的最后一个公共节点就是LCA。
