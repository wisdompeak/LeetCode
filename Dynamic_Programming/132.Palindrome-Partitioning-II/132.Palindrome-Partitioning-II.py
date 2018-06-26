class Solution:
    def minCut(self, s):
        """
        :type s: str
        :rtype: int
        """
        N = len(s)
        isPal = [[0 for _ in range(N)] for _ in range(N)]
        for i in range(N): isPal[i][i]=1
        for i in range(N-1): 
            if s[i]==s[i+1]: isPal[i][i+1]=1 
        for length in range(3,N+1):
            for start in range(N-length+1):
                if s[start]==s[start+length-1] and isPal[start+1][start+length-2]==1:
                    isPal[start][start+length-1]=1
                
        dp = list(range(1,N+1))        
        for i in range(1,N):
            if isPal[0][i]==1:
                dp[i]=1
            else:
                for j in range(i):
                    if isPal[j+1][i]==1:
                        dp[i]=min(dp[i],dp[j]+1)
        
        return dp[N-1]-1
