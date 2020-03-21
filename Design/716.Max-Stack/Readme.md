### 716.Max-Stack

此题初看很像 155.Min Stack，但本质有很大的不同，问题就在于popMax()这个操作，从一个数据结构的中段弹出元素，完全不是stack的风格。所以需要果断放弃155题的思路。那么哪些数据结构可以方便的删除中段的元素呢？似乎只有list了。

回顾 460.LFU Cache，我们已经接触过了list。其操作非常类似vector，而且还有一个非常巨大的优势，可以根据iterator来删除任意元素。本题的思路和460也非常相似，就是用到了一个有序的map，其key是list里的元素的数值，而value就是对应key的所有list元素的迭代器（可以理解为地址或指针）。

设计了以上的数据结构，操作就很容易了。对于popMax()，我们直接在Map的尾元素得到当前链表的最大值 x=(--Map.end())->first。然后auto it = Map[x].back()就是当前链表最顶端的最大值的地址。直接在list中删除即可 List.erase(it)。

特别注意，popMax(x)和pop(x)操之后，可能Map[x]的元素个数就是0了，此时一定要将Map删除这个key！


[Leetcode Link](https://leetcode.com/problems/max-stack)