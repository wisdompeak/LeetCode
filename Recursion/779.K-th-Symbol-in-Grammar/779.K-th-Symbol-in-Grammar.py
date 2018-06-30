class Solution:
    def kthGrammar(self, N, K):
        """
        :type N: int
        :type K: int
        :rtype: int
        """
        if N==1: return 0
        a = self.kthGrammar(N-1,(K+1)//2)
        if a==1:
            if K%2==1: return 1
            else: return 0
        else:
            if K%2==1: return 0
            else: return 1
