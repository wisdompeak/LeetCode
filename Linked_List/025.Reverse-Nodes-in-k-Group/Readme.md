### 025.Reverse-Nodes-in-k-Group

我们首先建立一个dummy放置在head之前。

举个例子，假设我们从p开始，对于未来的连续k个节点（不包括p）需要做方向的反转。
```
p -> x0 -> x1 -> x2 -> x3 -> x4 -> y
```
第一步就是要确定存在后续的k个节点。我们用一个指针q尝试走k步，走不完的话（提前遇到了空指针）说明这个链表已经不需要再做任何处理了，就返回dummy->next；否则的话我们就要做这个group的反转。
```cpp    
    ListNode* q = p;
    int count = 0;
    while (q->next && count < k)
    {
        q = q->next;
        count++;
    }
    if (count < k)
        return dummy->next;
```
做反转的时候，我们记得时刻维护cur, nxt, future这三个连续的指针。反转操作很简单，就是将nxt指向cur；但是更重要的是，之后需要更新这三个指针，使之整体后移一位。注意对于一个group，我们只需要做k-1次的反转。
```cpp
for (int i=0; i<k-1; i++) 
{
  nxt->next = cur;
  
  future = future->next;
  next = future;
  cur = next;
}
```
当这个group内部全部反转之后，别忘了要将原先的p指向当前该group的首指针（即x4，此时是cur），另外将x0指向y（此时是nxt）。
```
p --------------------------> 
    x0 <- x1 <- x2 <- x3 <- x4   y
     ---------------------------->
```
但此时x0已经没有被指向。所以，记得在最初的时候需要保留x0节点，即令```start = p->next```，
```cpp
start = p->next;

cur = p->next;
nxt = cur->next;
future = nxt->next;

for (int i=0; i<k-1; i++)
{ ... }

p->next = cur;
start->next = nxt;
```
