### 745.Prefix-and-Suffix-Search

此题仍然考察基本的TrieNode的数据结构，但是需要稍微设计一下。

如果根据前缀和后缀的双重信息来在字典树里找到一个单词呢？一个巧妙的设计就是把后缀加在单词前面，中间用"{"分隔，拼成一个新的单词，将这种新的单词加入字典树中，并在querry的时候查找。需要注意的是，一个正常的单词可能有k种后缀，k就是单词的长度，所以我们需要把这些所有的变化都加进字典树里。

为什么要用“{”做分隔符呢？因为它在ASCII中的位置恰好就在'z'后面，所以我们直接在每个TrieNode里开27个TrieNode*数组就行了。

如何快速查找weight呢？其实只要在加入字符串的时候，在每个node都标记该单词的id，而且后来的字符串id可以覆盖前面的，因为后面的认为是更大的weight。


[Leetcode Link](https://leetcode.com/problems/prefix-and-suffix-search)