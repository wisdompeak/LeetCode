### 1367.Linked-List-in-Binary-Tree

#### 解法1：递归
此题的递归解法和```572.Subtree-of-Another-Tree```一样。对于当前的两个节点，考察```isSame(head,root)```，如果不成立的话就递归处理```isSubPath(head, root->left)||isSubPath(head, root->right)```

#### 解法2：KMP
对于任意一条从root到leaf的支链，我们都可以看做是一个序列，可以用KMP来高效地搜索head所代表的模式串。不同的支链之间，我们用DFS来切换。

具体的做法是，定义全局变量dp[i]来表示从root开始的第i个（深度的）树节点、与linked list的“互相关后缀数组”，即dp[i]表示最大的长度k，使得截止第i个树节点（也就是某条路径的第i层）的后缀序列，恰好等于链表的前缀序列。我们注意到，对于树的不同的paths，如果它们共享一个深度为i的树节点，那么对它们而言，dp[i]都是一样的。而对于在不同分支的dp[i]，则彼此互不依赖。所以如果我们采用DFS，对于dp的更新不影响各条支路的搜索结果。

我们设计```dfs(node, i)```来计算当前树节点是node、并且深度为i时的dp[i]。根据KMP的算法，我们知道dp[i]仅依赖于dp[i-1]和模式串的后缀数组。如果当前节点计算得到的dp[i]==linkedList.size()，那么返回true；否则探索```dfs(node->left, i+1) || dfs(node->right, i+1)```
