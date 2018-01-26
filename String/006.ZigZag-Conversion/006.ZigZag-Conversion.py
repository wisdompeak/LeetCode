class Solution:
    def convert(self, s, numRows):
        """
        :type s: str
        :type numRows: int
        :rtype: str
        """        
        if numRows==1: return s
        M = numRows+numRows-2;
        N = (len(s)-1)//M+1
        res=s[0::M]
        print(M,N)
        for j in range(1,numRows-1):
            for i in range(N):
                if M*i+j<len(s): res+=s[M*i+j]
                if M*i+M-j<len(s): res+=s[M*i+M-j]
        res+=s[numRows-1::M]
return res;
