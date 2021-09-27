### 241.Different-Ways-to-Add-Parentheses

此题的突破口：任何多项式运算最终可以化简为最后的双目运算。只要遍历这个“最终的”双目运算符的位置,其将运算符前后两部分都用递归处理，然后这两部分的结果再两两组合即可.


[Leetcode Link](https://leetcode.com/problems/different-ways-to-add-parentheses)
