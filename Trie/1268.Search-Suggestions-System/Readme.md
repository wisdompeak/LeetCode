### 1268.Search-Suggestions-System

#### 解法1：
比较严谨的做法是用Trie。先将所有的products的单词建树。然后，根据searchWord的前缀（比如说前k个字母）在Trie中推进直至某个节点node，然后以node为根进行DFS，根据先序遍历的规则（优先走左下方的子树），找出字典序最小的三个到叶子节点的子路径。

#### 解法2：
有一种非常取巧的方法，那就是将所有product按照字典排序。然后查找searchWord在里面的位置（用lower_bound定位），得到的就是字典序恰好大于等于searchWord的那个单词。我们查看以这个单词开始的连续三个单词，是否与searchWord共享指定书目的前缀，是的话就相应收入囊中。

这种方法第一步排序的过程其实比较耗时，不过题目给出了```1 <= Σ products[i].length <= 2 * 10^4```，这就是暗示了字符串排序的复杂度是可以接受的。


[Leetcode Link](https://leetcode.com/problems/search-suggestions-system)
