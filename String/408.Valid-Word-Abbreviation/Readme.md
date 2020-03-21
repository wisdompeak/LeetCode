### 408.Valid-Word-Abbreviation

思路非常直接，遍历一遍abbr，移动abbr的同时也移动word的指针，看看每一步都是否对应。

需要注意的细节：
1. 数字不能有前导0. 比如word=ab, abbr=02就应该输出false.
2. abbr遍历完之后，word的遍历也应该恰好结束。即if (i!=word.size()) return false;


[Leetcode Link](https://leetcode.com/problems/valid-word-abbreviation)