### 092.Reverse-Linked-List-II

本题比较考验对于链表操作的细节。

我们先遍历到第m-1个和第m个节点。将第m-1个节点记为end_of_start，之后的next要重新指向逆序段的首节点。

从第m个节点到第n个节点，我们要做链表逆转的操作。基本的思想就是将向后指向的next，变更成向前指向。所以我们每操作一个cur，都要同时准确地知道prev和next。处理完之后，prev,cur,next都要正确地移动到下一个位置。最终处理完第n个节点后，此时的cur指向的是第n+1个节点，它就是第三段的首节点start_of_third，同时prev就是第二段的逆序的首节点。我们需要的操作是：
```cpp
end_of_first->next = start_of_third;
start_of_second->next = start_of_third;
```

[Leetcode Link](https://leetcode.com/problems/reverse-linked-list-ii)
