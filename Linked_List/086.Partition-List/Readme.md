### 86. Partition-List

solution 1: 不在内存中开辟新的节点

1. 创建两个新的指针头p,q： LinkNode\* p=new LinkNode(0)；
2. 在遍历原链表的过程中，将节点根据val分别归到p或q的链表中。
```cpp
  if (h->val<x)
  {
     p->next=h;
     p=p->next;
     h=h->next;
  }
```
3. 特别注意，原链表遍历结束后，q链表的结尾要赋值NULL，否则q的结尾仍然是原链表中的某个节点，其next仍然有指向（p链表中的某一个元素）。

solution 2: 在内存开辟新的节点
```cpp
  if (h->val<x)
  {
     p->next=new ListNode(h->val);
     p=p->next;
     h=h->next;
  }
```
这样就不需要手工在q结尾赋值NULL，因为新开辟的节点已经自动给next赋值NULL。


[Leetcode Link](https://leetcode.com/problems/partition-list)