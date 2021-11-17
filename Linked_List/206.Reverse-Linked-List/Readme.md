### 206.Reverse-Linked-List

此题是链表操作的常规考题。我们维护一个滑窗，last,cur,nxt表示三个连续的node。初始的时候，last=NULL, cur=head, nxt=cur->next. 对于每一个滑窗，我们要做的仅仅就是把cur从指向nxt改为指向last。然后移动滑窗，更新last,cur,nxt所对应的节点.

最终当cur==NULL是结束循环，此时反转链表之后的头指针就是last。
