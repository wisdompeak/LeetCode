### 224.Basic-Calculator

典型的栈的应用。需要设置两个栈
```cpp
  stack<int>nums;
  stack<int>sign;
```
nums用来存储数值，sign用来存储符号。这里需要有个小技巧，在字符串最开始添加一个+入栈，遇到'('也添加一个+入栈，这样保证每个数字（和小括号产生的中间结果）都在sign中有一个对应的符号位。

具体的算法是：遇到'('就将当前结果curResult入栈并清零。遇到')'就将当前结果与sign的栈顶元素结合形成新数（然后sign退栈），并加上nums的栈顶元素结合形成新数（然后nums退栈）。遇到符号就加入sign的栈。遇到纯数字就取出sign的栈顶元素结合


[Leetcode Link](https://leetcode.com/problems/basic-calculator)