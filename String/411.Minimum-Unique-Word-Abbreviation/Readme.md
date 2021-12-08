### 411.Minimum-Unique-Word-Abbreviation

此题不需要遍历所有的字典里的单词的缩写形式．

首先，我们应该注意到，缩写不会改变长度，所以两个长度不同的单词，他们的任何形式的缩写都不可能相同。所以对于字典里的那些与target的长度不一致的单词，完全可以忽略。

其次，targe的缩写方案有多少呢？不难判断，每一个字符只有两种选择：被缩写或者不被缩写。所以target的缩写形式只有2^m种可能。考虑到m是21，最多有2e6种缩写，是可以遍历过来的。对于无需剪枝的无脑遍历，使用bitmask来穷举所有缩写方式是最方便的，这与```LC 320.Generalized-Abbreviation```是一样的做法。当然，我们肯定先尝试长度短的缩写方法，再尝试长的缩写方法。所以需要将所有的缩写方法按照长度排序。

最后，我们对于target的每一种缩写方式abbr，都要与字典里的每一个单词word进行匹配，看是否abbr是否也是word的一个缩写。这个算法和```LC 408.Valid-Word-Abbreviation```是一样的。

所以总的时间复杂度是```o(2^m*n)```. 因为题目给出了m+log(n)<=21，所以```2^m*n<=2^21```，即时间复杂度是2e6级别，是可行的。

[Leetcode Link](https://leetcode.com/problems/minimum-unique-word-abbreviation)
