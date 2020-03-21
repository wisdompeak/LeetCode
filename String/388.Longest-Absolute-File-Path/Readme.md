### 388.Longest-Absolute-File-Path

特别注意：'\n'，'\t' 这种转义字符被认为是一个字符！

首先，根据'\n'将字符串拆分。然后，根据每个子字串前的'\t'的数目来确定它是第几级的。设置一个vector<vector<string>>dirs，比如第三级的字串就加入dirs[3]里面。

如果遇到一个字串表示的是文件名，则往前推其第i级的目录名，就对应了dirs[i]里面的最后一个字串。


[Leetcode Link](https://leetcode.com/problems/longest-absolute-file-path)