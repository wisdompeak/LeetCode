class Solution:
    def maxCoins(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        N = len(nums)
        nums = [1]+nums+[1]        
        dp = [[0 for _ in range(N+2)] for _ in range(N+2)]        
        for i in range(1,N+1):
            dp[i][i]=nums[i-1]*nums[i]*nums[i+1]  
        
        for Len in range(2,N+1):
            for i in range(1,N-Len+2):
                left,right = i,i+Len-1
                for k in range(left,right+1):
                    dp[left][right] = max(dp[left][right],dp[left][k-1]+nums[left-1]*nums[k]*nums[right+1]+dp[k+1][right])
                        
        return dp[1][N]

