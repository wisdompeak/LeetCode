### 095.Unique-Binary-Search-Trees-II

考虑构造DFS函数
```cpp
vector<TreeNode*> generateTreesDFS(int start, int end)
```
遍历每个可能的root(从start到end)，都可以递归调用DFS生成一系列左子树和右子树（以根节点数组表示）。

然后对每一个根节点，所有的左子树、右子树都两两配对，构成一个完整的树。返回所每个根节点组成的数组即可。
```cpp
             for (int i=start; i<=end; i++)
             {
                vector<TreeNode*> leftSubTree = generateTreesDFS(start, i - 1);
                vector<TreeNode*> rightSubTree = generateTreesDFS(i + 1, end);             
            
                for (int j = 0; j < leftSubTree.size(); ++j) 
                    for (int k = 0; k < rightSubTree.size(); ++k) 
                    {
                        TreeNode *node = new TreeNode(i);
                        node->left = leftSubTree[j];
                        node->right = rightSubTree[k];
                        subTree.push_back(node);
                    }
            }             
```            

