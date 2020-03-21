### 212.Word-Search-II

此题是用将常规的DFS算法与Trie的数据结构相结合。设计DFS函数
```
void DFS(int i, int j, TrieNode* node, string word, vector<vector<int>>&visited, vector<vector<char>>& board)
```
表示(i,j)为起点、node为Trie树的当前根、visited为已经经过的路径，求是否能在board里继续遍历出可以拼成完整单词的路径。拼出完整单词的依据是```node->isEnd==true```，无法继续的判据是```node->next[board[i][j]-'a']==NULL```


[Leetcode Link](https://leetcode.com/problems/word-search-ii)