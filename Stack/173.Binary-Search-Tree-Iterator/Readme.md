### 173.Binary-Search-Tree-Iterator

此题本质上是用迭代法（栈实现）来进行BST的中序遍历（也就是从小到大）。所以是94题的衍生。

所以该类的data member需要一个stack<int>Stack. 具体要点如下：

1. 初始化时，就将栈塞满到最小节点。（不断将左节点推入栈中）
```cpp
  while (root!=NULL)
  {
      Stack.push(root);
      root=root->left;
  }
```
2. 只要栈非空，就说明hasNext是true。
3. 输出next即输出当前栈顶元素。然后栈顶元素退栈，加入该元素的右节点并追溯到最底层。
```cpp
  TreeNode* node=Stack.top();
  int result=node->val; // 当前栈顶元素
  Stack.pop();  // 退栈
  node=node->right;  // 加入新的元素直至到当前最小值。
  while (node!=NULL)
  {
     Stack.push(node);
     node=node->left;
  }
```


[Leetcode Link](https://leetcode.com/problems/binary-search-tree-iterator)