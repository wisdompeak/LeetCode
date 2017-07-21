### 621.Task-Scheduler

此题非常类似  358.Rearrange-String-k-Distance-Apart。

设计一个大顶堆的priority_queue，每次取出权重最多的n+1个（或少于这个数目）字符，将其权重减一后再放回队列中。

需要注意的是，即使队列中的元素少于n+1，只要没有完成所有的任务，根据题意的idle设定，计数器仍需要count+=n+1. 只有最后一轮（弹出后队列为空）时，计数器才 count+= num，其中num时队列弹出前的元素个数。
