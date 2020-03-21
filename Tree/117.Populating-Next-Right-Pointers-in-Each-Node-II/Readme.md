### 117.Populating-Next-Right-Pointers-in-Each-Node-II

此题的难点在于如何只用constant extra space实现树的level order traversal。对于一般的树结构,这是无法做到的,但本题的特点是:这里定义的TreeNode的数据结构允许一个横向的链接next,为我们的level-order-tranversal提供了便利.

我们定义三个指针now,head,tail。初始状态now=root; head=tail=NULL。Now是用来指向正在遍历的当前层的节点，head和tail指向下一层的头节点和尾节点。

我们在横向遍历now指针的时候，考察now->left和now->right，根据情况,不断更新head和tail. head只有一种情况需要更新,那就是如果head==NULL的话.对于tail的更新原则,永远就是让tail->next指向now的子节点(也就是引入新的tail),然后自己也右移一位。

当now==NULL时，说明当前层已经遍历完毕，然后怎么办呢?精彩的地方来了!就让now指向head即可，因为head就是下一层的头指针.然后将head和tail清空（指向NULL）,就重复了上面一段的操作.


[Leetcode Link](https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii)