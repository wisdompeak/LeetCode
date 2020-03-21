### 676.Implement-Magic-Dictionary

此题特征就是用Trie树，实现高效的单词搜索。Trie树的一些基本操作应数量掌握，包括构建树 buildTree(string word, TrieNode* node)，搜索一个单词是否在此字典树内 inDictionary(string word, TrieNode* node).

对于单词abcdefg，先考虑置换第一个字母a，换成其他字母后，考察bcdefg是否是在这个字典树node内，需要调用inDictionary。如果从a到z的置换都不成功，则将根节点下降一层node=node->next['a'-'a']，同时word=word.substr(1)，于是就将原问题转化为在新的字典树node理考察新的word（bcdefg），这样可以递归调用整个search的过程。


[Leetcode Link](https://leetcode.com/problems/implement-magic-dictionary)