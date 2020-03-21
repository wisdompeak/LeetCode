### 211.Add-and-Search-Word

这是字典树的典型题，考察了Trie的各种基本操作。

首先是TrieNode的类型及构造函数:
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
注意：1.类定义结束之后要加分号。2.构造函数必须显式地声明为public（否则默认为private）。

其次是字典树的数据添加:
```cpp
    void addWord(string word) 
    {
        TrieNode* node=root;
        for (int i=0; i<word.size(); i++)
        {
            char ch=word[i];
            if (node->next[ch-'a']==NULL)
                node->next[ch-'a']=new TrieNode();
            node=node->next[ch-'a'];
        }
        node->isEnd=true;
    }
```
本质是不断开辟子树的过程，将原本是NULL的子节点new出一个实际的内存空间。

最后的字典树的查询，则是用到了DFS，根据索引下沉到相应的子节点，和二叉树的遍历类似。


[Leetcode Link](https://leetcode.com/problems/add-and-search-word)