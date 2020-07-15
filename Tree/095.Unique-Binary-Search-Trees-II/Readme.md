### 095.Unique-Binary-Search-Trees-II

这道题如何构造DFS函数很有讲究。函数的参数应该是start和end，输出应该是一系列由start到end元素构成的BST。注意这样的BST不止一个，除了根节点可以在start~end之间任意选择外，左子树和右子树在下一轮递归中也会有很多解。所以在当前的返回值应该要穷举出所有这样的BST。

考虑这样构造DFS函数
```cpp
vector<TreeNode*> generateTreesDFS(int start, int end)
```
遍历每个可能的root(从start到end)，然后确定了左子树、右子树包含的元素。递归调用DFS分别生成一系列左子树和右子树。

重点来了！然后对每一个根节点，需要所有的左子树、右子树都两两配对，构成一个完整的树。所以对每一个左右子树组合，都要不断实例化这个根节点，然后加入到结果数组中。
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
另外需要注意的细节：
如果start>end，需要返回的是一个包含NULL的```vector<TreeNode*>```，而不是空数组。否则之后的二重循环就可能无法展开。


[Leetcode Link](https://leetcode.com/problems/unique-binary-search-trees-ii)
