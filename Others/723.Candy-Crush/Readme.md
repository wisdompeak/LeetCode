### 723.Candy-Crush

基本思想是，对于每一个不存遍历过的、非零的board[i][j]，往上下、左右两个方向搜索：如果同一直线上有超过三个相同的格子就将他们标记为已经遍历。最终所有遍历过的格子置零，然后在纵方向上塌落。

注意，如果有塌落的话，就需要再次递归调用自身，直至某回合的遍历之后board没有任何改动为止。


[Leetcode Link](https://leetcode.com/problems/candy-crush)