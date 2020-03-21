### 385.Mini-Parser

本题涉及了一种不常见的自定义数据结构NestedInteger，需要好好分析。

本题一个可以取巧的地方在于：任何一个NestedInteger变量都可以完全看做是一个vector<NestedInteger>，哪怕这个list里的元素只有1.这样就避免了考虑这个NestedInteger变量可能仅有一个int的麻烦。

另外，注意到NestedInteger类没有给出清零的操作，所以必须尽量不借助多余的变量来实现栈的操作。

具体的算法是：
1. 遇到s[i]=='['时，就要新开了一个NestedInteger的变量。这个变量的本质要是一个List，后续的同级元素都是它的子元素。怎么利用构造函数新开一个类的对象呢？
```cpp
Stack.push(NestedInteger());
```
这样，这个变量不用命名、不用赋初值就可以直接放入栈里。
  
2. 遇到s[i]是数字开头时，把完整的数字段抽取出来后得到val。需要这个val转成NestedInteger并放入当前Stack.top()里成为它的一个元素。
```cpp
Stack.top().add(Integer(val));
```

3. 遇到s[i]==']'时，说明Stack.top()已经把同一层级的所有元素收罗干净了。它本身整个就要投入自己上一级的NestedInteger中，成为它的一个元素。
```cpp
NestedInteger temp=Stack.top();
Stack.pop();
Stack.top().add(temp);
```
特别注意的是，上述语句的前提条件是 Stack.size()>1


[Leetcode Link](https://leetcode.com/problems/mini-parser)