### 232.Implement-Queue-using-Stacks

此题设置两个stack。

一个简单的想法是：第二个栈仅仅用作临时倾倒stack1元素的备用容器。每次需要remove或get第一个栈的栈底元素时，将Stack1的所有元素（除栈底）倒入Stack2中，然后操作之后再把Stack2的元素都倒回Stack1中。这种方法有点浪费时间。

更好的设计是：因为Stack2已经把元素反向，所以任何类似Queue队首的操作都可以在Stack2里操作，取Stack2的栈顶即可。而对于Queue队尾的push操作，则留在Stack1完成。只有当Stack2已经空了的时候，才需要把Stack1里的元素倒入Stack2.


[Leetcode Link](https://leetcode.com/problems/implement-queue-using-stacks)