### 1109.Corporate-Flight-Bookings

本题用到了非常常见的差分数组的思想。

对于[i,j,k]，我们不需要从i到j把这些元素全部遍历一遍来加上k，这样效率很低，特别是当i和j间隔非常大的时候。正确的方法是用差分数组diff[x]表示```val[x]-val[x-1]```，只记录“值的变化”而不是“值本身”。当diff构造完之后，可以从第一个元素开始，不断的通过```cur=cur+diff[i]```来恢复得到val[i]的值。

本题的本质就是```LC.370 Range Addition```


[Leetcode Link](https://leetcode.com/problems/corporate-flight-bookings)
