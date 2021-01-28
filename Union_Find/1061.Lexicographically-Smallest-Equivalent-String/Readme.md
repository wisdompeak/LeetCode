### 1061.Lexicographically-Smallest-Equivalent-String

最基本的UF的模板题。我们根据A[i]和B[i]的"等效"关系进行Union，得到所有联通集合。对于每个集合，我们推选最小的字母作为代表。

然后遍历S，对于每个字母，我们替换为它所在Union的代表字母。得到的就是字典序最小的“等效字符串”
