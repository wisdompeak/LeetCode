### 761.Special-Binary-String

首先，应该容易分析出：对于一个special string S，它整体可以拆分为一个或若干个不可再拆分的、连续的sub special string。对于每个不可再连续拆分的sub special string S'，它的首位一定是1，末位一定是0，中间一定还是一个special string，于是可能还可以继续拆分下去。

写成式子就是： 任何 S = （1）ABCDEF（0）,首位的1和末位的0可能存在，而中间的ABCDEF都还是不可连续拆分的speical string，

因为题目规定的swap的规则必须是在相邻的special string之间进行，所以对于任何一个S,只能通过内部的ABCDEF这些S'之间的位置调整,使得S自身调整至字典序最大（暂时不考虑ABCDEF内部的调整，假设它们已经各自字典序最优）。那么如何调整ABCDEF使得S的字典序最大呢？显然，只要让ABCDEF按照字典序从大到小排列即可。

这就有了递归的思路。把S拆成ABCDEF，让它们各自递归成字典序最大，然后优化后的ABCDF按字典序重排，技能得到字典序最大的S。


[Leetcode Link](https://leetcode.com/problems/special-binary-string)