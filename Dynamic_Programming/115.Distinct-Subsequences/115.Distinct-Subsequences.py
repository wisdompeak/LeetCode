class Solution:
    def numDistinct(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: int
        """
        M,N = len(s),len(t)
        s = "#"+s
        t = "#"+t
        dp = [[0 for _ in range(N+1)] for _ in range(M+1)]
        for i in range(M+1):
            dp[i][0] = 1
        for i in range(1,M+1):
            for j in range(1,N+1):                
                if s[i]==t[j]:
                    dp[i][j]+=dp[i-1][j-1]                
                dp[i][j]+=dp[i-1][j]
        return dp[M][N]
        
        
