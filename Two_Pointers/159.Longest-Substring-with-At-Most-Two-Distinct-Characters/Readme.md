### 159. Longest-Substring-with-At-Most-Two-Distinct Characters  

需要一个记录每种字符出现次数的映射，这里为了加快效率，我们不用Map，而是直接用一个数组 vector<int>Map(128,0)，用字符的ascii码作为index，注意需要开辟至少256个空间才能装下所有字母字符。  

另外还需要一个计数器count还记载目前指针范围内有几种字符。  

按照个人的习惯，最外层用for循环来遍历j。然后分情况讨论：
1. Map[s[j]]>0，说明s[j]已经被合法收录，故可继续往后遍历j。
2. Map[s[j]]==0 && count<2，说明s[j]可以被合法收录，故可继续往后遍历j。
3. Map[s[j]]==0 && count==2，说明i\~j已经包含两种字符了，故需要不断退s[i]直至count<2。注意此时仍要收录s[j]。
在每种情况下，i~j都是包含两种字符的合法子串，故都要update一下result。


[Leetcode Link](https://leetcode.com/problems/longest-substring-with-at-most-two-distinct-characters)