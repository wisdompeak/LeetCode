### 1237.Find-Positive-Integer-Solution-for-a-Given-Equation

对于二元变量的二分搜索，情况远比一元变量复杂得多。可以考虑递归的形式：假设x0是x方向上的二分，y0是y方向上的二分，那么
1. 如果f(x0,y0)>z，则说明可以将x变小（y的范围不变），或者将y变小（x的范围不变）。
2. 如果f(x0,y0)<z，则说明可以将x变大（y的范围不变），或者将y变大（x的范围不变）。
3. 如果f(x0,y0)==z，说明{x0,y0}是一对解；但特别注意，搜索并不能停止，此时可以将x变大的同时将y变小，或者反之，都可能继续搜索到z。

另外，上述的方法会带来显著的重复搜索，所以算法效率并不高。


[Leetcode Link](https://leetcode.com/problems/find-positive-integer-solution-for-a-given-equation)