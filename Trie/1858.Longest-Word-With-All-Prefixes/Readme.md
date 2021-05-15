### 1858.Longest-Word-With-All-Prefixes

首先是构造字典树的基本操作。然后我们要在这个字典树里，从根开始找一个最长的路径，使得路径上的每一个节点都是某个单词的end（即节点的isEnd属性为true）。DFS即可。
