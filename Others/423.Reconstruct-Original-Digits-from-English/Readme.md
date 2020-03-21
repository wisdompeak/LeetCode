### 423.Reconstruct-Original-Digits-from-English

此题不必用DFS蛮干，有非常巧妙的解法。

观察0,2,4,6,8,对应的单词zero,two,four,six,eight. 可以发现对应的z,w,r,x,g这个五个字母都是各自独有的（考虑全部十个单词）。 所有在一个长字符串中，有多少z,w,r,x,g,就说明了正好有多少个0,2,4,6,8. 

那剩下的五个单词数目如何确定呢？其实，在长字符串中刨除了之前说的这五个单词之后，"five","seven","one","three","nine" 又“依次”“分别”有各自的特征字母f,v,o,h,i。也就是说除去这个单词后，剩下的有多少个字母f，就说明有多少个5；再除去所有5之后，剩下的有多少v，就说明有多少个7，依次类推。


[Leetcode Link](https://leetcode.com/problems/reconstruct-original-digits-from-english)