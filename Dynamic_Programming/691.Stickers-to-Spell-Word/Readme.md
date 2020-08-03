 ### 691.Stickers-to-Spell-Word
 
设置状态数组dp[i],dp的大小是 N = 2^n, 其中n是target的大小。怎么理解？将dp的索引i进行二进制拆解，i的每一个bit表示的是target对应位置的字符是否得到了满足。比如n=3时，dp数组的大小N=8，对应的状态有 000,001,010,011,100,101,110,111. 举个例子，i=3 (即011)表示target的末两位的字符得到了满足，但第一位的字符还没有得到满足。dp[i]表示在状态i下，需要的sticker的最少数目。

注意：这种状态的排列有一个非常好的性质。任何状态，只可能由位于其前面的状态转移得到，不可能从后面的状态转移得到。比如i=3(即 011)这个状态，只可能从i=0,1,2转移过来（通过使用某些合适的sticker）；再比如i=4(即100)这个状态，只可能从i=0转移过来。这种状态转移的性质，非常适合dp根据i从前往后的遍历。

所以，dp的大循环就是 ```for (state=0; state<(1<<n); state++)```. 对于该状态state，我们尝试每一个sticker[k]，计算状态i经过sticker[k]的帮助后得到的状态new_state（注意已经分析过new_state肯定是大于state的），那么dp[new_state]就可以得到更新```dp[new_state]=min(dp[new_state], dp[state]+1)```

所有的状态i都遍历过之后，答案的输出就是 dp[N-1]


[Leetcode Link](https://leetcode.com/problems/stickers-to-spell-word)
