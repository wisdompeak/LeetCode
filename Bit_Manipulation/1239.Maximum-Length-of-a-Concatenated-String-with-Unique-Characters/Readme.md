### 1239.Maximum-Length-of-a-Concatenated-String-with-Unique-Characters

本题就是一个基本的DFS爆搜。注意不要误认为是LIS。

一个long long变量有32个bit，我们可以用来记录dfs的过程中已经收集了哪些字符，记做变量bits。当前DFS过程中的bits与某个新字符串对应的bits做“AND”之后，如果不为零时，说明二者有重复的字符，搜索可以终止。

最终的答案就是搜索过程中bits出现的最多的1的各种，即```__builtin_popcount(bits)```
