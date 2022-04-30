### 061.Rotate-List
此题对于链表的操作包括：

1. 确定链表的总长度Len，注意如果Len==0时的处理（此时可以顺便记录末尾节点end）
2. 确定实际需要旋转的次数 k=k%Len  
3. 令p从头指针前进 Len-k-1 步，就到了断开链表的位置。
4. 将p->next作为新的head，原本的end之后指向原本的head，再把p的next指向NULL，

[Leetcode Link](https://leetcode.com/problems/rotate-list)
