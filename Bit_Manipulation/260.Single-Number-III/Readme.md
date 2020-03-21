### 260.Single-Number-III

这是一道经典题．首先，我们容易想到把所有数字亦或起来，看看得到什么．假设最后的结果是x和y，那么我们最后得到的是x和y．这有什么用呢？

显然x,y不相等的话，那么x^y不可能为零．所有必然有一个bit位置上，x和y是不同的．那么我们就可以把所有的数字按照这个位置的bit值分为两类，其中一类和x相同（偶数个），另一类和y相同（也是偶数个）．这两类各自做亦或和的操作，相同的数都会cancel掉，剩下来的就是x和y本身了．

此题需要用到的一些bit操作技巧是：

```x&(x-1)```：　表示unset the rightmost set bit

```x^(x&(x-1))```：　表示只保留 the rightmost set bit

```log2(x^(x&(x-1)))```：　表示the rightmost set bit的位置


[Leetcode Link](https://leetcode.com/problems/single-number-iii)