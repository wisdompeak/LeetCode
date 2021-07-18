# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def reverseKGroup(self, head, k):
        """
        :type head: ListNode
        :type k: int
        :rtype: ListNode
        """
        dummyHead = ListNode(0)
        dummyHead.next = head
        h = dummyHead
        while h.next:
            count = 0
            left = h
            while (h.next and count<k):
                h = h.next
                count+=1
            if count<k: return dummyHead.next
            right = h.next
            
            a,b = left.next, left.next.next
            for i in range(k-1):                
                temp = b.next
                b.next = a
                a,b = b, temp                
                            
            h = left.next
            left.next = a
            h.next = right
        return dummyHead.next
            
