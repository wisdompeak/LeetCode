class Solution:
    def combine(self, n, k):
        """
        :type n: int
        :type k: int
        :rtype: List[List[int]]
        """
        results = []
        def DFS(start,nums):
            if (len(nums)==k):
                results.append(nums)
                return
            if (len(nums)+n-start+1<k):
                return
            for i in range(start,n+1):
                DFS(i+1,nums+[i])
        nums = []
        DFS(1,nums)
        return results
