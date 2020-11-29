### 1666.Change-the-Root-of-a-Binary-Tree

这道题的dfs过程其实应该是从leaf往上走直至root。对于每一个node，我们要更改它的left，right和parent。node->parent应该指向node的前驱节点（也就是处于leaf->root路径上的那个child）。node->left应该指向往上的路径（也就是原先的parent）。node->right应该指向它的另外一个child（即非leaf->root路径上的那个child）。然后递归处理leaf->root路径上的下一个节点。

此题另外有一个陷阱是题意要求对于root的处理，与其他node的处理方法略有不同。只需要将node->parent指向前驱节点，再将处于leaf->root路径上的那个child置为NULL即可。不需一定要将非路径上的child迁移到右节点。
