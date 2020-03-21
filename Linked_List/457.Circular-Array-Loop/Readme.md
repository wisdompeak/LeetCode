### 457.Circular-Array-Loop

看到题目要求用o(1)的空间判断一个array里是否存在loop，就应该条件反射地想到用快慢指针的方法。这个方法在linked list的数据结构里经常用到，因为链表无法反向遍历或这按index遍历。此题虽然是数组，但由于空间要求的限制，不得不利用链表里的这个技巧。

此题要注意的细节是，getNext(pos,nums,dir)函数应该在两种情况下返回”错误“的提示。一种情况是该点nums[pos]和设定的遍历方向dir不同，违反题意，那么就直接返回”错误“。另一种情况是，getNext得到的是本身节点（仅对于慢指针）的话，说明这个方向的搜寻陷入了dead end，不能构成一个环。

有了以上两个报错预判作为while循环的条件，就可以放心地让快慢指针各自前进，直至两者相遇。
```py
        while (getNextTwo(fast,nums,dir)!=-1 and getNext(slow,nums,dir)!=-1):
                fast,slow = getNextTwo(fast,nums,dir),getNext(slow,nums,dir)
                if (fast==slow): break
```
跳出之后根据```(getNextTwo(fast,nums,dir)!=-1 and getNext(slow,nums,dir)!=-1)```判断是否真的loop达成。

如果loop没达成，则让慢指针再跑一遍，从起点到它的dead end一路都标记为0，以后这些元素就不用访问。这额外的一遍访问会增加一倍o(n)的时间，不会改变整体时间的数量级。


[Leetcode Link](https://leetcode.com/problems/circular-array-loop)