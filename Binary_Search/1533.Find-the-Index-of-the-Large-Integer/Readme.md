### 1533.Find-the-Index-of-the-Large-Integer

本题本质是三分搜索。我们将一个区间分为三分ABC，其中A和B的区间大小相等。如果A、B区间和相等，那么异类就在区间C里面。如果A、B区间和不相等，那么异类就在A、B较大的区间里面。

注意外层循环的条件变成了```while (right-left+1 >= 3)```。原因是区间大学小于3的时候无法成功三分区间。

[Leetcode link](https://leetcode.com/problems/find-the-index-of-the-large-integer/)
