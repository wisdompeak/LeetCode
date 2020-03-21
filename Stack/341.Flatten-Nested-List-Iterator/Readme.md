### 341.Flatten-Nested-List-Iterator

仔细分析数据结构的定义。vector\<NestedInteger\>包含的是元素是NestedInteger类型. 当对元素做.getInteger()操作后得到的才是整形；做.getList()操作后得到的是vector\<NestedInteger\>类型。

设计一个stack\<NestedInteger\>Stack的堆栈。

hasNext()的目的，就是将Stack的栈顶元素不断展开（如果对应的是List数据的话），直至栈顶元素isInteger()为止。则下一步的next()就是读取栈顶元素并抽取整形数据，同时退栈。


[Leetcode Link](https://leetcode.com/problems/flatten-nested-list-iterator)