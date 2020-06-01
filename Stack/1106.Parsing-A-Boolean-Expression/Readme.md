### 1106.Parsing-A-Boolean-Expression

本题和上周周赛的最后一题（1096. Brace Expansion II）属于同一类型，相对来说更容易些。

对于这种带有括号优先级的expression parsing，栈或者递归的写法都是比较常见的。

#### 解法1：栈
我们需要设立两个栈，一个存储的是操作符，```stack<char>stackOp```；另一个存储的是操作数，注意操作数是个数组，```stack<vector<int>>stackNums```

进栈的特征是遇到操作符，将这个操作符和手头的操作数组nums都压入栈后清空。退栈的特征是遇到右括号，这个时候调用stackOp的栈顶操作符，来指挥怎么eval手头的nums，并与stackNums的栈顶元素（也是个数组）合并。当然，两个栈都要吐出栈顶元素。其余的时候，只需要不断增加手头的操作数组nums的长度即可。

#### 解法2：递归
遇到一个操作符的话，也就意味着马上有一个左括号i。我们找到和它平级的右括号j，这样[i,j]之间的字符串的处理可以写成一个递归函数。递归函数返回的就是一个bool值。递归的边界就是字符串不再包括子括号了，那么这时候需要做的就是根据操作符来eval一堆操作数nums即可。

[Leetcode Link](https://leetcode.com/problems/parsing-a-boolean-expression)
