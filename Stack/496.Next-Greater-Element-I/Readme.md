### 496.Next-Greater-Element-I

此题用普通模拟的方法遍历会很慢。高级的算法是利用到单调栈，时间复杂度是o(n)。

维护一个单调递减的栈，即当nums[i]小于栈顶元素时就不断入栈。当发现nums[i]大于栈顶元素时，说明nums[i]就是此栈顶元素所遇到的第一个greater number，把这个信息记录在一个Hash Map里，然后把栈顶元素退栈；重复上述操作直至nums[i]小于栈顶元素，再将其入栈并继续遍历nums。


[Leetcode Link](https://leetcode.com/problems/next-greater-element-i)