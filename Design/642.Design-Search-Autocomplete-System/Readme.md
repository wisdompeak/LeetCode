### 642.Design-Search-Autocomplete-System

我们将所有的句子都构建入一棵字典树。对于每个节点（字母），我们都维护一个```句子-频次```的统计。也就是说，注入句子S时，我们将沿途经过的节点都标记上```freq[S]+=1```.

当依次读入input时，我们维护从root往下走的指针，移动至该单词对应的节点，读取它的freq取出前三名即可。freq需要使用一个自动排序的数据结构。

记得当input遇到#时，要将之前input的完整句子，从root开始再次构建入这棵字典树。


[Leetcode Link](https://leetcode.com/problems/design-search-autocomplete-system)
