### 694.Number-of-Distinct-Islands

一个岛屿的形状，可以通过BFS遍历的路径来表示。遍历的起始点永远是这个岛屿的左上角（x最小的条件下、y最小）。每遍历到一个点，就在path中加入相邻可以继续遍历的点的方向。比如可以往左、往右、往下遍历，就path+="013"；如果不可以继续遍历，那就不加任何信息。

注意每遍历一个点，都需要用*号隔开。

最后这个path字符串就代表了唯一一种岛屿的形状。


[Leetcode Link](https://leetcode.com/problems/number-of-distinct-islands)