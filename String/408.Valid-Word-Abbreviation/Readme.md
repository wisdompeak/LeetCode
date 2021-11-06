### 408.Valid-Word-Abbreviation

典型的双指针。遍历一遍abbr，移动abbr的指针的同时，也相应地移动word的指针，看看每一步都是否对应。具体地说，就是abbr的字母和word字母对应，abbr的数字和word里相同数目的字母对应。

需要注意的细节：
1. 数字不能有前导0. 比如word=ab, abbr=02就应该输出false.
2. abbr遍历完之后，word的遍历也应该恰好结束。即if (i!=word.size()) return false;


[Leetcode Link](https://leetcode.com/problems/valid-word-abbreviation)
