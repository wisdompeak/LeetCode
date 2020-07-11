### 430.Flatten-a-Multilevel-Doubly-Linked-List

本题的基本思想是，对于一个节点h，我们需要依次拼接h本身、遍历h->child得到的链表，遍历h->next得到的链表。考虑到第三部分要接在第二部分的末尾，所以这个“遍历”的递归函数的返回值应该是整个链表的最后一个节点。

所以，当h的next和child都存在的时候，大致的思路应该是这样的：
```cpp
Node* dfs(Node* h)
{
  child = h->child;
  next = h->next;
  Node* childEnd = dfs(child);
  Node* nextEnd = dfs(next);

  h->next = child;   // h和child拼接
  child->prev = h;
  childEnd->next = next;  //childEnd与next拼接
  next->prev = childEnd;

  return nextEnd;
}  
```
但是在实际处理的时候，考虑当child和next各自是否为NULL时，具体的代码写法会不一样。
1. child和next都为空：直接返回h
2. child不为空，next为空：将h与child拼接后，返回的是childEnd
3. child为空，next不为空：返回的是nextEnd.
