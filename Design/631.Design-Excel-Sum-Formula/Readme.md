### 631.Design-Excel-Sum-Formula

本题需要注意的是操作的完整性。

Set：如果该单元格已经有公式，则需要先把公式从Map里清除，再对该单元格赋值。

Get：不是简单地从table里读数据。如果该单元格已经有公式，则该单元格依赖于其他单元格且可能未被更新。所以需要先执行一遍公式，即sum(r,c,Map[to_string(r)+c])更新该单元格的内容，再返回。

Sum：在根据公式计算时，对于所需要的单元格数值，不能简单地从table里读取，而是要通过get操作来实现，因为那个单元格可能存在公式且未更新。


[Leetcode Link](https://leetcode.com/problems/design-excel-sum-formula)