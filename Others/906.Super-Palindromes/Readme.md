### 906.Super-Palindromes

对于最大值为1e18的super palindrome，其平方根最大为1e9。因为这个平方根也要求是回文数，因此我们通过“遍历回文数的前半部分再镜像”的方法，最多只需要遍历1\~1e5就可以构造出1~1e9范围内所有的回文数，继而检查一下它的平方是否是超级回文数即可。整个时间复杂度控制在1e5的数量级，是可以接受的。


[Leetcode Link](https://leetcode.com/problems/super-palindromes)
