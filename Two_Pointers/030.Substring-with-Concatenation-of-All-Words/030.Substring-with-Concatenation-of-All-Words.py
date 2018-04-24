class Solution:
    def findSubstring(self, s, words):
        """
        :type s: str
        :type words: List[str]
        :rtype: List[int]
        """
        if len(words)==0: return []
        M = len(words[0])        
        Table = collections.defaultdict(int)        
        COUNT = 0
        for word in words:
            Table[word]+=1
            COUNT +=1
        results=[]    
        
        for start in range(M):
            Map = collections.defaultdict(int)
            i = start
            flag = 1
            count = 0 
            head  = i
            while (i<len(s)):
                
                if i+M>len(s) or (s[i:i+M] not in Table):                    
                    Map.clear()
                    count = 0
                    head = i+M;
                    i = head         
                elif Map[s[i:i+M]]==Table[s[i:i+M]]:
                    Map.clear()
                    count = 0
                    head += M
                    i = head                    
                else:
                    Map[s[i:i+M]]+=1
                    i+=M
                    count+=1
                                    
                if count==COUNT:
                    results.append(head)
                    Map.clear()
                    count=0
                    head += M
                    i=head
                            
        return results
