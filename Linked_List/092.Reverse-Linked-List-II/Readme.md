### 092.Reverse-Linked-List-II

本题的基本思路很明显，我们需要将原列表拆分为三部分。然后对中间一部分进行链表反转操作（参考 206.Reverse-Linked-List），最后将三部分拼接起来。

需要注意的是left和right可能很极限，也就是说原题可能本质上是反转整个链表。所以方便的处理方法是前面添加一个dummy节点，末尾也虚拟地认为有一个NULL节点。这样我们就一定能够把整个链表分为实实在在的三部分。然后应用上述的算法。

另外注意，所谓的将链表拆违三部分，并不是找到每一部分的首尾就完了，还要把尾节点的next置为NULL，这样才能形成一个单独的链表。否则可能会有各种意想不到的bug。

[Leetcode Link](https://leetcode.com/problems/reverse-linked-list-ii)
