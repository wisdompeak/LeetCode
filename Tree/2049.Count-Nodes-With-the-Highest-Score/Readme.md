### 2049.Count-Nodes-With-the-Highest-Score

本题本质只要设计一个递归函数dfs(node)来计算以node为跟的子树包含的元素个数即可。这样的话，如果删除掉node节点本身，那么剩下的三部分就是```dfs(node->left), dfs(node->right), n - 1 - dfs(node->left) - dfs(node->right)```. 只要把这三部分的非零元素相乘，就是一个score。所以在dfs(node)的同时，就可以把对应的score算出来。而实现整棵树的dfs，只要o(n)时间，均摊起来每个节点只需要o(1)。
