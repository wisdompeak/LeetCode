# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def reorderList(self, head):
        """
        :type head: ListNode
        :rtype: void Do not return anything, modify head in-place instead.
        """        
        if not head: return None
        
        fast,slow = head,head
        while fast.next and fast.next.next:
            fast = fast.next.next
            slow = slow.next
        head2 = slow.next
        slow.next = None
                  
        prv,h = None,head2
        while h:
            nxt = h.next
            h.next = prv
            prv = h
            h = nxt
        head2 = prv       
            
        h = ListNode(0)
        h1,h2 = head,head2
        while h1 and h2:
            h1_temp, h2_temp = h1.next, h2.next
            h.next = h1     
            h = h.next
            h.next = h2
            h = h.next
            h1,h2 = h1_temp, h2_temp
        if h1:
            h.next = h1
