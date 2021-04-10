# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:  
    record = {}
    def rob(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        if not root: return 0
        if root in self.record: return self.record[root]
                
        plan1 = self.rob(root.left)+self.rob(root.right)        
        plan2 = root.val
        if root.left:
            plan2+= self.rob(root.left.left)+self.rob(root.left.right)
        if root.right:
            plan2+= self.rob(root.right.left)+self.rob(root.right.right)
            
        self.record[root]=max(plan1,plan2)
        return self.record[root]
