class Solution:
    def superEggDrop(self, K, N):
        """
        :type K: int
        :type N: int
        :rtype: int
        """
        dp = [0]*(K+1)
        m = 0
        while dp[K]<N:
            m+=1
            dp_temp = list(dp)
            for k in range(1,K+1):
                dp[k] = dp_temp[k-1]+dp_temp[k]+1
        return m
            
