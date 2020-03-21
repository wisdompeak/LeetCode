### 225.Implement-Stack-using-Queues

比较直观的解法：使用一个队列，需要读或者退出队列末尾的元素时，可重复将队首元素弹出并加回队列，重复len-1次即可（len是队列的长度）。缺点是，即使是每次读队列末尾元素也要绕一圈。

更好的解法是：在每次往队列push元素的时候，就进行一次大反转，使得队列里的元素其实是以从新到旧的顺序排放的。这样，每次top()和pop()的操作都只要o(1)的时间操作。


[Leetcode Link](https://leetcode.com/problems/implement-stack-using-queues)