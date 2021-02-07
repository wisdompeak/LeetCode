### 652.Find-Duplicate-Subtrees

#### 解法1 
结合LeetCode 449，任何一颗二叉树都可以序列化成一个带有唯一特征的字符串。我们dfs整棵树，对于每个节点都作为子树进行序列化，利用序列化的字符串作为key创建Hash表，归类所有key相同的子树。

#### 解法2
此题有o(N)的巧妙解法。

任意两棵子树结构相同的充要条件是：node->val相同、左子树结构相同、右子树结构相同。我们将所有结构相同的子树都用同一个ID来表示，那么任意两棵子树结构相同的充要条件变成：node->val相同、左子树ID相同、右子树ID相同。这三个条件又可以序列化成为一个key，于是对于两棵子树（节点），相同的key <=> 相同的三个条件 <=> 相同的子树 <=> 相同的ID。

对于一棵子树，它的```key = node->val + getId(node->left) + getId(node->right)```. 同时我们再利用一个映射key2Id将高维的key转化为一个整数ID：如果已经出现过这个key，返回已经对应的ID，否则就生成一个新ID。最终getId(node)返回的就是key2Id[key]，这会返回给上一级供node的父节点用来生成父节点的ID。

根据key的出现次数统计key2Count.如果对于某个节点，发现key2Count[key]==2，就在答案中记录该节点。

[Leetcode Link](https://leetcode.com/problems/find-duplicate-subtrees)
