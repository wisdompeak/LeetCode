### 588.Design-In-Memory-File-System

这种明显带有层级结构、从上而下的搜索，提示了可以用典型的Trie数据结构。

以前的Tire树，都是通过字符-若干字符的跨接。这里则是字符串-若干字符串的跨接。该怎么设计呢？答案是用哈希表。
```cpp
class TrieNode
{
    public:
    map<string,TrieNode*>Map;
    bool isFile;
};
```
这样的话，从上到下的转移可以通过```node = node->Map[str]```来实现。


[Leetcode Link](https://leetcode.com/problems/design-in-memory-file-system)