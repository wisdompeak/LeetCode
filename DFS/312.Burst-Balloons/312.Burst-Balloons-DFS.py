class Solution:
    def maxCoins(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        N = len(nums)
        nums = [1]+nums+[1]        
        self.dp = [[0 for _ in range(N+2)] for _ in range(N+2)]
                
        def DFS(left,right):
            if left>right: return 0
            if self.dp[left][right]!=0: return self.dp[left][right]                       
            result = 0
            for k in range(left,right+1):
                result = max(result, DFS(left,k-1)+nums[left-1]*nums[k]*nums[right+1]+DFS(k+1,right))
            self.dp[left][right] = result
            return result                
        
        return DFS(1,N)
