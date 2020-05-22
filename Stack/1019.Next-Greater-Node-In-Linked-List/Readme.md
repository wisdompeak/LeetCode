### 1019.Next-Greater-Node-In-Linked-List

本题和```Next Greater Element```并没有本质的区别。我们维护一个单调递减的栈，当如果新元素大于栈顶元素时，栈顶元素退栈，并且可以知道栈顶元素的next greater element就是新元素。

需要注意的是，ret的结果并不是顺次更新的。所以栈的类型应该设计成pair，需要包括元素的数值和索引，这样方便将结果存入对应的ret[i]中。
