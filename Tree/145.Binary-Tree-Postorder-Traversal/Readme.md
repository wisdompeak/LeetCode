### 145.Binary-Tree-Postorder-Traversal

本题和用栈实现二叉树的先序遍历和中序遍历的基本思路很相似，但更难一些。

既然是后序遍历，那么就要在遍历完左子树、右子树之后再读取数值。所以作为中继点的根节点会经过三次。第一次是通过根节点把左子树压入栈，第二次是通过根节点把右子树压入栈，第三次才是读取。所以我们设置一个set，来标记每个在退栈时被访问过的节点。

算法的基本结构保持和先序遍历算法一致：
1. 如果遇到非空节点，从根节点开始一路靠左入栈，入栈时不读取节点数值；
2. 当遇到空节点时，找到栈顶元素（局部的根节点）。如果之前没有被收录在set里，则记录之，并通过它把其右子树压入栈；
3. 如果栈顶元素已经被set记录过，此时说明其右节点已经遍历完毕，可以读取数值并将该节点退栈。（思考，退栈后root应该如何赋值？答案：把root赋值为NULL，这样就可以循环到第2步）
```cpp
        while(root!=NULL || !Stack.empty())
        {
            if (root!=NULL)
            {
                Stack.push(root);
                root=root->left;
            }
            else
            {
                root=Stack.top();
                if (Map.find(root)==Map.end())
                {
                    Map[root]=1;
                    root=root->right;
                }
                else
                {
                    results.push_back(root->val);
                    Stack.pop();
                    root=NULL;
                }
            }
        }
```        


[Leetcode Link](https://leetcode.com/problems/binary-tree-postorder-traversal)