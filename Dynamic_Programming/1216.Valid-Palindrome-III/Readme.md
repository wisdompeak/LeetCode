### 1216.Valid-Palindrome-III

此题和1312题很相似的想法。想要将一个字符串s变成一个回文串（无论是通过增加还是删除），一个技巧就是构造另一个字符串t是s的逆序。于是，如果要求增加字符，那么s和t的shorted common supersequence就是需要增加的最少字符；如果要求删除字符，那么s和t的longest common subsequence就对应着需要删除的最少字符。

本题求出s和t的LCS后，只需要判断s的长度减去LCS的长度（即对于s而言最少需要删除的字符）是否小于等于k即可。
