class Solution:
    def hIndex(self, citations):
        """
        :type citations: List[int]
        :rtype: int
        """
        if len(citations)==0: return 0
        if len(citations)==1: return min(citations[0],1)
        counts = collections.Counter(citations)
        L = list(counts.items())
        L = sorted(L,key=lambda x:x[0],reverse=True)
        H_paper = 0
        print(L)
        for i in range(len(L)):                    
            if H_paper+L[i][1] == L[i][0]:
                return L[i][0]
            elif H_paper+L[i][1]>L[i][0]:
                return max(L[i][0],H_paper)
            else:
                H_paper+=L[i][1]
        return H_paper
                
                
        
        
