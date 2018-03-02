class Solution:
    def findTargetSumWays(self, nums, S):
        """
        :type nums: List[int]
        :type S: int
        :rtype: int
        """
        Sum = sum(nums)
        if (abs(S)>Sum): return 0
    
        N = len(nums)
        dp = [[0 for _ in range(2*Sum+1)] for _ in range(N)]
        dp[0][nums[0]+Sum]+=1;
        dp[0][-nums[0]+Sum]+=1;
        
        for i in range(1,N):
            for s in range(-Sum,Sum+1):                
                s1=s+nums[i]
                s2=s-nums[i]          
                                
                if (abs(s1)<=Sum): dp[i][s+Sum] += dp[i-1][s1+Sum]
                if (abs(s2)<=Sum): dp[i][s+Sum] += dp[i-1][s2+Sum]
                
        return dp[N-1][S+Sum]
