class Solution:
    def distinctSubseqII(self, S):
        """
        :type S: str
        :rtype: int
        """
        last = [0 for _ in range(26)]                
        dp = 0
        M = 1e9+7
        
        for ch in S:
            dp_temp = dp            
            dp = dp_temp + (dp_temp +1 - last[ord(ch)-ord('a')])
            dp %= M
            last[ord(ch)-ord('a')] = dp_temp+1
            last[ord(ch)-ord('a')] %= M
        return int(dp)
