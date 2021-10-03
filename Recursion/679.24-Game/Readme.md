### 679.24-Game

此题和```LC 241 Different Ways to Add Parentheses```与```LC 2019 The Score of Students Solving Math Expression```类似的套路。

我们遍历这个四个数字的permutaion。对于任意一种permuation ```A B C D```，我们本质上需要做的就是任意添加运算符（加减乘除）和括号（改变运算顺序），查看整个式子eval的结果是否包含24. 

具体的做法就是递归。我们将某个permutation拆解为两部分分别递归处理，再将两个部分eval出来的结果两两组合，配上加减乘除，就得到对于这个permutation我们所能计算出的所有可能值。大致的代码是
``` 
for x: eval(AB)
  for y: eval(CD)
    rets.insert({x+y, x-y, x*y, x/y});
```

需要注意，所有的牌必须处理成浮点，因为涉及到除法。


[Leetcode Link](https://leetcode.com/problems/24-game)
