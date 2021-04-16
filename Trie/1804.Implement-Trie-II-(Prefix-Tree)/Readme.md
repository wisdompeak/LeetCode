### 1804.Implement-Trie-II-(Prefix-Tree)

这道题比较全面地考察了trie的操作。

我们对于每个node，设置两个成员变量count1和count2. 每添加一个单词，我们将该单词沿途经过的所有节点的count1都增1，并且将该单词最后一个字母的节点的count2增1.

对于```int countWordsEqualTo(string word)```，我们返回该单词最后一个字母的节点的count2. 对于```int countWordsStartingWith(string prefix)```，我们返回该前缀最后一个字母的节点的count2。

对于```erase(word)```操作，我们将该单词沿途所经过的所有节点的count1都减1，如果某个节点减1之后的count1变成了0，说明该支路往下都只属于这个word，可以直接将次节点删除。另外，记得将该单词最后一个字母的节点的count2减1（如果该节点还存在的话）。
