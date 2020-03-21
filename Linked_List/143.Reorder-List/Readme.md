### 143.Reorder-List.cpp

此题不难，但是比较繁琐，需要耐心理清思路，细致地操作指针。

其中对于一段链表进行逆序操作的基本算法是：不断从源链表首摘下一个节点（同时指针后移），拼接到目标链表首（同时指针前移）。

得到两段链表之后，交替摘取节点拼接到新链表上。


[Leetcode Link](https://leetcode.com/problems/reorder-list)