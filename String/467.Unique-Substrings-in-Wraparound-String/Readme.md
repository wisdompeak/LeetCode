### 467.Unique-Substrings-in-Wraparound-String

注意s串的性质，其子串必然是递增的。发现这一点后，只要是在p中的所有递增子串，都是s的字串。

那么p中有多少不同的递增子串呢？任何不同的递增字串，只需要两个参数就能确定其独特性。一个是起始字符，另一个是字串的长度。于是只要遍历p的每一个字符，找出以其为开头的最长递增字串即可。比如说p中以'a'开头的递增字串的最大长度是n，那么就有n种不同的以'a'开头的递增字串。

创建一个Hash表，遍历p[i]。以遍历的字符p[i]作为key，记录以p[i]开头的递增字串的最大长度（这个value会随着p的遍历而不断被更新）。最终结果就是把所有key的value都加起来。


[Leetcode Link](https://leetcode.com/problems/unique-substrings-in-wraparound-string)