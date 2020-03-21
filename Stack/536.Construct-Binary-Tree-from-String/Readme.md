### 536.Construct-Binary-Tree-from-String

典型的栈的应用。创建 stack<TreeNode*>Stack.

遇到左括号就把current入栈；

遇到右括号就退栈一个元素作为current的父节点：根据规则，current优先作为左子节点，如果父节点已经有左子节点，则current作为它的右子节点。然后更新current为此时的那个父节点。

遇到数字串，则开辟新节点current并赋值。注意负号。


[Leetcode Link](https://leetcode.com/problems/construct-binary-tree-from-string)