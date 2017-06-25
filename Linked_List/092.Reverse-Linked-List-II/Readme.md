### 092.Reverse-Linked-List-II

#### 将一段链表逆序
可以设置一个节点front==NULL，然后遍历中段节点的时候不断把节点加到front前面去，然后更新front保持位于新中段的队首。有多少元素就操作多少次。
```cpp
        ListNode* front = NULL;
        for (int i=m; i<=n; i++)
        {
            ListNode* temp = p->next; // save the next node
            p->next=front;
            front=p;
            p=temp;
        }
```        

另外要注意的是，在逆序操作前要保存中段的首元素的地址，因为逆序操作后该节点就成了中段的尾地址，需要靠它来链接后段链表。
