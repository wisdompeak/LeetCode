### 779.K-th-Symbol-in-Grammar

此题是典型的递归解法。第N行的第K个，取决于第N-1行的第(K+1)/2个。于是依次往上回溯，直至追踪到第N==1行的元素是0.


[Leetcode Link](https://leetcode.com/problems/k-th-symbol-in-grammar)