### 438.Find-All-Anagrams-in-a-String

1. 注意到本题的查验子串的窗口长度是固定的s.size()，所以不需要双指针，单指针即可。
2. 需要构造字符的哈希表时，用数组而不是map，效率更高。但记得一定要赋初值 vector<int>Map(256,0)
3. 数组之间判断是否相等的比较，直接用 == 即可。
4. 仔细考虑循环条件，不要遗漏最后一次比较。

完全相同的问题有 567.Permutation in String


[Leetcode Link](https://leetcode.com/problems/find-all-anagrams-in-a-string)