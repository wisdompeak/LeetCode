### 1868.Product-of-Two-Run-Length-Encoded-Arrays

一个比较容易的写法是in-place修改freq。比如数组一的指针位于i，数组二的指针位于j，那么我们可以找到的彼此有相同val的频次就是```k=min(encoded1[i][1],encoded2[j][1])```，将```{val,k}```收入答案。然后将encoded1[i][1]和encoded2[j][1]分别减去k。再根据更新后的频次是否减到了0来判断是否需要移动指针i或者j。

注意最后需要将答案进一步压缩，因为可能有相邻元素的val是相同的。
