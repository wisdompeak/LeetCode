### 648.Replace-Words

此题显而易见，是用Trie来实现单词（词根）的查找。

对于Trie类型的基本功操作包括：
1. Trie类型的定义：包括两个成员变量，构造函数
```cpp
class TrieNode
{
  public:
   TrieNode* next[26];
   bool isEnd;
  
  TrieNode()
  {
    for (int i=0; i<26; i++)
      next[i]=NULL;
    isEnd=false; 
  }  
};
```
2. Trie的单词添加
```cpp
void addWord(TrieNode* root, string word)
{
    TrieNode* node=root;
    for (int i=0; i<word.size(); i++)
    {
        char ch=word[i];
        if (node->next[ch-'a']==NULL)
          node->next[ch-'a']==new TrieNode();
        node = node->next[ch-'a'];
    }
    node->isEnd=1;
}
```
3. Trie的单词查找。在本题中，只要能追踪到叶子节点 isEnd==true 即说明找到词根
```cpp
bool flag = DFS(root,word,0); // 递归调用

bool DFS(TrieNode* root, string word, int k)
{
    if (root->isEnd==true)
      return true;
    if (k==word.size())
      return false;
    for (int i=0; i<26; i++)
    {
       if (DFS(root->next[word[i]-'a'],word,k+1))
          return true;
    }
    return false;
}
```


[Leetcode Link](https://leetcode.com/problems/replace-words)