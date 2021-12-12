### 1676.Lowest-Common-Ancestor-of-a-Binary-Tree-IV

此题和```LC.236```一模一样的思想。令```int dfs(node)```表示以node为根的子树里面包含了多少个指定的节点。假设题目给出的nodes的个数是n，那么在从下往上返回的过程中，第一个发现dfs返回值是n的节点必然就是所有nodes的LCA。
