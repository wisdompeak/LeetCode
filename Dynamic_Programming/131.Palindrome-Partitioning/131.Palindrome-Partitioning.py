class Solution:
    def partition(self, s):
        """
        :type s: str
        :rtype: List[List[str]]
        """
        N = len(s)
        dp = [[0 for _ in range(N)] for _ in range(N)]
        for i in range(N):
            dp[i][i]=1
        for i in range(N-1):
            if s[i]==s[i+1]: dp[i][i+1]=1
        for length in range(3,N+1):
            for start in range(N-length+1):
                if s[start]==s[start+length-1] and dp[start+1][start+length-2]==1:
                    dp[start][start+length-1]=1     
                                   
        ret,combo = [],[]
        def DFS(start,combo,ret):
            if start==N: 
                ret.append(combo)
                return
            for i in range(start,N):
                if dp[start][i]==1: 
                    DFS(i+1,combo+[s[start:i+1]],ret)
            return        
        
        DFS(0,combo,ret)
        return ret
