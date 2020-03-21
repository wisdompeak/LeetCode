### 1268.Search-Suggestions-System

#### 解法1：
比较严谨的做法是用Trie。根据searchWord的前缀（比如说前k个字母）在Trie中推进直至某个节点，然后以这个节点为根，用DFS的方法、根据先左后右的规则，找出最多三个合法的子路径（即能够拼成一个product）。

特别注意，此题中的product允许有重复，所以在TrieNode定义中，传统的bool isEnd需要改造为int count，并在构造整颗树的时候用它来计算有多少个重复（即共享完全相同的路径）的product。在DFS的过程中，如果推进到某个节点的count>1，说明会有多于1个product有着相同的名字，我们需要把它们都算上。

#### 解法2：
有一种非常取巧的方法，那就是将所有product按照字典排序。然后查找searchWord在里面的位置（用lower_bound定位），得到的就是字典序恰好大于等于searchWord的那个单词。我们查看以这个单词开始的连续三个单词，是否与searchWord共享指定书目的前缀，是的话就相应收入囊中。

这种方法可以不必理会products中是否存在重复。但是第一步排序的过程其实比较耗时，不过题目给出了```1 <= Σ products[i].length <= 2 * 10^4```，这就是暗示了字符串排序的复杂度是可以接受的。


[Leetcode Link](https://leetcode.com/problems/search-suggestions-system)