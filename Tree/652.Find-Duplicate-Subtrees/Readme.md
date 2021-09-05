### 652.Find-Duplicate-Subtrees

#### 解法1 
结合LeetCode 449，任何一颗二叉树都可以序列化成一个带有唯一特征的字符串。我们dfs整棵树，对于每个节点都作为子树进行序列化，利用序列化的字符串作为key创建Hash表，归类所有key相同的子树。

#### 解法2
解法1的一个缺陷是序列化得到的key字符串可能会非常长。解决方法是将每个key都及时转化为一个数字ID，这样可以有效减少key的长度。

例如，对于根节点是node的子树，我们定义它的```string key = to_string(node->val) + "#" + to_string(getId(node->left)) + "#" + to_string(getId(node->right))```。其中getId就是将左子树（或者右子树）的序列化结果用映射的数字ID代表。显然通过这种方式生成的node的key，会比纯序列化的结果短很多。

对于当前生成的key，如果在key2Id中已经出现过，那么说明当前的子树就是一个duplicate subtree。否则，我们就给这个key映射一个新的ID，一般就令为 ```key2Id[key] = key2Id.size()+1```. 这个结果就是getId(node)的返回值。

另外，我们还需要统计所有key出现的次数. 当某个key第二次出现时，我们就把当前的节点加入答案中。

[Leetcode Link](https://leetcode.com/problems/find-duplicate-subtrees)
