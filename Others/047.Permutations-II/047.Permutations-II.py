class Solution:
    def permuteUnique(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        def insert(P,k):
            result = []
            for p in P:
                for i in range(len(p)+1):                    
                    result.append(p[:i]+[k]+p[i:])
                    if i<len(p) and p[i]==k: break
            return result
        
        P = [[]]
        for k in nums:
            P = insert(P,k)
        return P
