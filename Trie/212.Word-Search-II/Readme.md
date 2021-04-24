### 212.Word-Search-II

此题是用将常规的DFS算法与Trie的数据结构相结合。设计DFS函数
```
void DFS(int i, int j, TrieNode* node, string word, vector<vector<int>>&visited, vector<vector<char>>& board)
```
表示(i,j)为起点、node为Trie树的当前节点、visited为已经经过的路径，求是否能在board里继续遍历出可以拼成字典树里面任意的完整单词。能拼出完整单词的依据是走到某个节点时```node->isEnd==true```，无法继续的判据是```node->next[board[i][j]-'a']==NULL```

在新的数据集中，上面的方法会TLE。改进之处是每探索到一个单词之后，就将该单词从字典树里移出，避免重复搜索同一个单词。怎么修改字典树呢？我们不需要真地去删除节点，只需要给每个节点添加一个count标记。在最初建立字典树的时候，每添加一个单词，我们就给沿途的节点的count加一。删除单词的时候，就给每个节点的count减一。当我们遍历字典树的时候，如果发现某个节点的count等于0时，就可以认为这个节点已经不存在了。

[Leetcode Link](https://leetcode.com/problems/word-search-ii)
