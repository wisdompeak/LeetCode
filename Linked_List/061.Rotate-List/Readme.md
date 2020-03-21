###061.Rotate-List
此题对于链表的操作包括：

1. 确定链表的总长度Len，注意如果Len==0时的处理（此时可以顺便记录末尾节点end）
2. 确定实际需要旋转的次数 k=k%Len  
3. 利用快慢指针p和q，找到需要断开的地方，即p和q之间。
4. p之后指向NULL，q作为新的head，原本的end之后指向原本的head。


[Leetcode Link](https://leetcode.com/problems/rotate-list)