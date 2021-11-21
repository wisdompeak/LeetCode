### 143.Reorder-List.cpp

此题不难，但是比较繁琐，需要耐心理清思路，细致地操作指针。

本题的算法是，先求得整体的长度count。于是我们将整个链表分割为两部分：前者有(count+1)/2个节点；后者再进行反转链表的操作。

得到这两段链表之后，交替摘取节点拼接到新链表上。


[Leetcode Link](https://leetcode.com/problems/reorder-list)
