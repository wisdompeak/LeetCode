class Solution:
    def palindromePairs(self, words):
        """
        :type words: List[str]
        :rtype: List[List[int]]
        """
        Map = {}          
        for i, w in enumerate(words):
            Map[w] = i            
        words = sorted(words,key = lambda i:len(i))  
        
        result = []
        Set = set()
        for w in words:
            for L in range(len(w)+1):
                if (w[0:L]==w[0:L][::-1] and w[L:][::-1] in Set):                    
                    result.append([Map[w[L:][::-1]],Map[w]])
                if (w[L:]==w[L:][::-1] and w[0:L][::-1] in Set):
                    result.append([Map[w],Map[w[0:L][::-1]]])
            Set.add(w)
        return result                
