class Solution:
    def shortestPalindrome(self, s):
        """
        :type s: str
        :rtype: str
        """        
        r = s[::-1]
        i = len(s)
        while not s[0:i]==r[len(s)-i:]:
            i-=1        
        return r[0:len(s)-i]+s
