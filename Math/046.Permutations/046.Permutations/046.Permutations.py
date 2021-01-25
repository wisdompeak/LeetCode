class Solution:
    def permute(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        def insert(P,k):
            result = []
            for p in P:
                for i in range(len(p)+1):
                    q = p[:i]+[k]+p[i:]
                    result.append(q)
            return result
        
        P = [[]]
        for i in nums:
            P = insert(P,i)
        return P
