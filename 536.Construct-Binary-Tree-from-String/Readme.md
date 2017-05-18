### 536.Construct-Binary-Tree-from-String

典型的栈的应用。创建 stack<TreeNode*>Stack.

遇到左括号就把current入栈；

遇到右括号就退栈一个元素作为current的父节点，并更新current为这个父节点（如果父节点没有左子节点，那么说明current是它的左子节点）；

遇到数字串，则开辟新节点current并赋值。注意负号。
