### 94.Binary-Tree-Inorder-Traversal

利用栈来实现二叉树中序遍历的经典题。
```cpp
while (root!=NULL || !Stack.empty())
{
   ...
}
```
1.从根节点开始一路靠左将子节点入栈，入栈时不读取节点数值；
```cpp
  if (root!=NULL)
  {
    Stack.push(root);
    root=root->left;
  }
```
2.当遇到空节点时（最底层），找到此刻栈顶元素，读取数值，并通过它把其右子树入栈，此栈顶元素就算完成任务可以退栈了。
```cpp
  else 
  {
    root=Stack.top();
    Stack.pop();
    results.push_back(root->val);
    root=root->right;
  }
```
