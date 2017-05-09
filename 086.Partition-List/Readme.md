### 86. Partition-List
1. 创建两个新的指针头p,q： LinkNode* p=new LinkNode(0)；
2. 在遍历原链表的过程中，将节点根据val分别归到p或q的链表中。
```cpp
  if (h->val<x)
  {
     p->next=h;
     p=p->next;
     h=h->next;
  }
```
3. 特别注意，原链表遍历结束后，q链表的结尾要赋值NULL。否则测试程序在检查结果的时候可能无法抵达结尾。
