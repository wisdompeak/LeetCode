class Solution(object):
    def combine(self, n, k):
        """
        :type n: int
        :type k: int
        :rtype: List[List[int]]
        """
        i=0
        p=[0]*k                     # pay attention to this
        results=[]
        while (i>=0):
            p[i]=p[i]+1            
            if (p[i]>n):
                i-=1;
            elif (i==k-1):
                results.append(p[:])  # pay attention to this
            else: 
                i+=1
                p[i]=p[i-1]
        return results    
