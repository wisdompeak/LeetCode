### 1286.Iterator-for-Combination

此题和```LC77.Combinations```的解法二一样，就是求next combination. 总体思想是从最低位（最后一位）开始考察，检查这个字符是否能替换为大一点的。如果不能的话，那么再往前找高一位的字符。从后往前一直找到某一位字符cur[i]，发现可以替换为稍大一点的字符，记为charcaters[j]。那么从cur[i:]就相应地填为charcaters[j:].

"检查这个字符是否能替换为大一点的"的意思是：看cur[i]能否取一个比当前更大的字符，同时第i个之后的保持递增顺序的那些字符也是有解的（即不会没有字符可以选）。


[Leetcode Link](https://leetcode.com/problems/iterator-for-combination)