### 1106.Parsing-A-Boolean-Expression

本题和上周周赛的最后一题（1096. Brace Expansion II）属于同一类型，相对来说更容易些。

对于这种带有括号优先级的expression parsing，栈+递归是比较容易舒服的写法。

注意，一般而言，dfs的返回值是一个数组（或者在1096中是一个集合）而不是一个单独的值。这是因为这个数组中的元素，最终会用“add”或者“union”这种题目定义优先级最低的操作进行化简，而后面可能还会遇到优先级更高的操作，所以没有必要着急现在就进行合并。


[Leetcode Link](https://leetcode.com/problems/parsing-a-boolean-expression)