### 386.Lexicographical-Numbers

对于字典序列的next，核心就是
1. 尝试往后加0, 否则
2. 找最低的、加1不需要进位的位置，在该位置加1后，舍弃之后的位置即可。


[Leetcode Link](https://leetcode.com/problems/lexicographical-numbers)
