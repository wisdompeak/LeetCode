### 1593.Split-a-String-Into-the-Max-Number-of-Unique-Substrings

本题并没有巧解，只能暴力枚举判断。DFS来搜索分组的方案是比较可行的方法。如果遇到当前分组不满足条件时，就可以终止剩余字符的分组。

注意，不要试图用状态压缩来暴力枚举判断。因为它无法实现DFS的提前剪枝。
