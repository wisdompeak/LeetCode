### 880.Decoded-String-at-Index

假设我们当前的容器里面有一串已经解码的字符串t，其字符的长度是count。

这个时候如果我们接下来处理的是一个字符ch，那么显然，说明第count+1个字符一定就是ch。特别地，如果```count+1==K```，那么ch就是答案，否则我们还会继续往后扫描S。

这个时候如果我们接下来处理的是一个数字num，那么说明解码容器里的字符串t要增加num倍的长度。如果```count*num < K```，说明还没有走到第K个字符，我们还需要继续往后扫描S。反之```count*num >= K```的话，说明这么多字符串t的串联用力过猛，我们可能只需要部分t的串联即可到达K。考虑到t就是“循环节”，所求的第K个字符，其实就是在这个循环节里找第```K%count```元素即可。至此，我们发现，```decodeAtIndex(S,K)```此时变成了```decodeAtIndex(t,K%count)```，原来这题就是一个递归的解法。

特别注意，如果```K%num==0```的话，我们需要输出的是循环节里最后一个字符。


[Leetcode Link](https://leetcode.com/problems/decoded-string-at-index)