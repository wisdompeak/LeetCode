### 1948.Delete-Duplicate-Folders-in-System

此题的本质就是```652.Find-Duplicate-Subtrees```. 我们给树的每个节点对应的subtree设计Hash。对应同一个Hash Key的subtree都是duplicate的。我们在第二次遍历整棵树的时候，遇到duplicate subtree就终止并返回即可。

本题与652的区别是，判断两棵子树A与B是否相同的定义，与子树的根节点本身无关。只要A的所有子节点与B的所有子节点相同，那么A与B就判定是相同的。所以我们给子树node设计Hash的时候，不需要考虑node本身，而是考虑node的所有子节点的Hash以及所有子节点的val。即
```
string key(node) = key(node->child_1) + "#" + node->child_1->val + "#" + key(node->child_2) + "#" + node->child_2->val + "#" ....
```
注意为什么我们既要每个child的key，又要child的val。这是基于我们之前对于key的定义，key(child)本身并不包括child的val。所以为了正确地表示node的所有子节点，我们需要把child的这两部分都加入key(node)里面。

此外我们会发现，这样递归的结果会造成顶端节点的key越来越长。同652的做法，我们可以将key映射成一个数字ID，这样就避免了key长度的膨胀。每个node的key的长度只与有多少一代孩子有关。即
```cpp
int getId(node) {
  string key(node) = getId(node->child_1) + "#" + node->child_1->val + "#" + 
                     getId(node->child_2) + "#" + node->child_2->val + "#" + ....
  return getId(node) by mapping key(node) to a new Id;
}
```

第一次遍历这棵树的时候，我们记下每个节点的key并更新key在整棵树里出现的次数。在第二次遍历整棵树的时候，我们如果发现某个节点的key出现过了两次以上，就不再打印和继续访问。
