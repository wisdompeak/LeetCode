### 378. Kth Smallest Element in a Sorted Matrix  

#### 解法１
矩阵的规律是：如果matrix[i][j]不是最小的，则matrix[i+1][j]和matrix[i][j+1]就都不用考虑。或者matrix[i][j]是最小的，则matrix[i+1][j]和matrix[i][j+1]就能进如考虑范围。  

所以类似BFS的算法，设计一个小顶堆的Priority_queue，每次出列最小值之后，将最小值邻接的matrix[i+1][j]和matrix[i][j+1]加入这个队列会自动排序。当出列k个数之后就是答案。

类似的题目：373

#### 解法2
以上的解法在新的测试集下会非常慢．更优的方法是binary search.

显然，答案的上限是```matrix[0][0]```,下限是```matrix[N-1][N-1]```．对于这个区间的任意一个ｘ，我们可以计算出这个矩阵里小于等于ｘ的元素有多少，定义为```smallerOrEqual(x)```．如果```smallerOrEqual(x)<k```，说明这个ｋ太小了不是想要的答案，应该往上调整，所以```left=x+1```.反之```smallerOrEqual(x)>=k```，说明ｋ可能是答案，但可以再缩小一点试一试，因此```right=x```．　（当然，更直接一点，其实如果直接得到```smallerOrEqual(x)==k```的话就已经说明ｋ就是答案了）

那么如果写这个```smallerOrEqual(x)```呢？这个思路其实和 240. Search a 2D Matrix II 非常相似．对于这种行列都排序的矩阵，我们可以从左下角（其实右上角也可以）出发，遇到```matrix[i][j]<=x```，说明从(i,j)之上的整列都```smallerOrEqual(x)```，于是就可以往右移动一列．　否则的话，我们就往上移动一行．　这样直至我们走出这个矩阵，走过的路径就自动将矩阵划分为了左上和右下两个部分，就是以smallerOrEqual(x)为分界的．

这个性质非常好用，请大家多多练习．（从左下角出发或者从右上角出发）．


[Leetcode Link](https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix)