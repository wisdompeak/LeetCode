### 631.Design-Excel-Sum-Formula

我们定义两个数据结构：
```
    int Val[27][26];
    vector<string> Exp[27][26];
```
前者存数值，后者存表达式。

Set：对Val的对应位置赋值。如果该位置已经有Exp，则需要将Exp清空。

Get：如果该位置没有Exp，则从Val里读取。否则就需要解析表达式，对每个位置上递归调用Get，然后相加。

Sum：对Exp的对应位置赋值，然后调用Get。


[Leetcode Link](https://leetcode.com/problems/design-excel-sum-formula)
