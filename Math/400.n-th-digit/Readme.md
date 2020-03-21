### 400.n-th-digit

首先判断这个n-th digit所属的数字t总共有几个digit。我们将这个n不断减去"所有一位数的digit的总数"，再减去"所有两位数的digit的总数"，再减去"所有三位数的digit的总数"...最后一次n大于零的时候，就可以确定我们其实要求的，就是所有k位数中的第n个digit。

我们将此时的n除以k，其实就可以确定是第几个k位数；然后将n对于k取余数，就可以确定是那个数的第几位。答案就出来了。


[Leetcode Link](https://leetcode.com/problems/n-th-digit)