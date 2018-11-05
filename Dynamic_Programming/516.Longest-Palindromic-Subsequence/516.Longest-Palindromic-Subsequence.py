import numpy as np
class Solution:
    def longestPalindromeSubseq(self, s):
        """
        :type s: str
        :rtype: int
        """
        N = len(s)
        vec0,vec1,vec = [0]*N, [1]*N, [0]*N
        # vec[i]: the longest palindrome subsequece starting at i and length Len
        # vec0[i]: the longest palindrome subsequece starting at i and length Len-2
        # vec1[i]: the longest palindrome subsequece starting at i and length Len-1
        
        for Len in range(2,N+1):
            for i in range(0,N-Len+1):
                if s[i]==s[i+Len-1]:
                    vec[i] = vec0[i+1]+2
                else:
                    vec[i] = max(vec1[i],vec1[i+1])
            vec0 = vec1.copy()
            vec1 = vec.copy()
        return vec1[0]
                
        
        
        
        
                
                
            
