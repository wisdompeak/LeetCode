### 2416.Sum-of-Prefix-Scores-of-Strings

常规的字典树的应用。在建树的时候，我们给每个节点node标记一个count，表示从root->node的这条路径是多少个word的前缀。在查询的时候，我们在字典树里遍历word的前缀，所到之处的count就是当前前缀的score了。
