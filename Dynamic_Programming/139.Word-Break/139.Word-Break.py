class Solution:
    def wordBreak(self, s, wordDict):
        """
        :type s: str
        :type wordDict: List[str]
        :rtype: bool
        """
        N = len(s)
        dp=[False for i in range(N+1)]
        dp[0]=True
        s = '0'+s
        for i in range(1,N+1):
            for j in range(1,i+1):
                if dp[j-1] and s[j:i+1] in wordDict:
                    dp[i]=True
        return dp[N]
