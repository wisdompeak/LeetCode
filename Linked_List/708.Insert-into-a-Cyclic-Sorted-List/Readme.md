### 708.Insert-into-a-Cyclic-Sorted-List

本题的一个能简化思维的方法就是，提前找到这个链表中的最小值的节点．这样的话，后续的插入就会很方便．
```cpp
Node* h = head->next;
Node* pre = head;
while (h!=head && pre->val<=h->val)
{
   h = h->next;
   pre = pre->next;
}
```
这样，得到的h就是整个链表中最小的节点了．于是，容易找到一个合适的插入位置：
```cpp
Node* NewHead = h;        
while (h->next!=NewHead && !(h->val<=insertVal && h->next->val>=insertVal))
    h = h->next;
```


[Leetcode Link](https://leetcode.com/problems/insert-into-a-cyclic-sorted-list)