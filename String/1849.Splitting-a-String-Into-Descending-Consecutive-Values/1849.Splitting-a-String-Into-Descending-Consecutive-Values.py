class Solution(object):
    def splitString(self, s):
        """
        :type s: str
        :rtype: bool
        """
        def dfs(s, cur, num):
            if cur==len(s):
                return True
            for l in range(1, len(s)-cur+1):
                if num-1==int(s[cur:cur+l]) and dfs(s, cur+l, num-1):
                    return True
            return False        
        
        for l in range(1, len(s)):
            if dfs(s, l, int(s[0:l])):
                return True
        return False
