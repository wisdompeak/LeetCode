### 556.Next-Greater-Element-III

此题和`031.next permuation`一模一样

首先，从低位到高位找到第一个不满足升序的数字。显然，如果从低位到高位都是升序的话，那么找不到任何可以比这个数字更大的变换了。

假设找到这样的数字在第n+1位（记做k），那么在1\~n这个n个低位数字中找到恰比k大的数字（记做m），交换k和m。于是变换后的第n+1位就这么定下来了（可以分析出这就是最小的改动）。剩下来的第1~n位（记得其中有一个是之前调换过来的k），我们让它们按照降序排列即可。


[Leetcode Link](https://leetcode.com/problems/next-greater-element-iii)
