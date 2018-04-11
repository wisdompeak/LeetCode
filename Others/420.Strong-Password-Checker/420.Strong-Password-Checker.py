class Solution:
    def strongPasswordChecker(self, s):
        """
        :type s: str
        :rtype: int
        """
        upper,lower,digit = 0,0,0
        for i in range(len(s)):
            if s[i]>='0' and s[i]<='9': digit=1
            if s[i]>='a' and s[i]<='z': lower=1
            if s[i]>='A' and s[i]<='Z': upper=1
        MissingType = 3-digit-lower-upper
        
        # case 1
        if len(s)<6: return max(MissingType, 6-len(s))
        
        # case 2
        i = 0
        change = 0
        while i<len(s):
            j = i
            while (j+1<len(s) and s[j]==s[j+1]):
                j+=1
            l = j-i+1
            change += l//3
            i = j+1
        if len(s)<20: return max(MissingType, change)
            
        # case 3
        i = 0
        to_delete = len(s)-20
        change,one,two, deleted= 0,0,0,0
        
        while i<len(s):            
            j = i
            while (j+1<len(s) and s[j]==s[j+1]):
                j+=1
            l = j-i+1
                        
            if l>=3:
                change+=l//3
                if l%3==0: one+=1
                if l%3==1: two+=1
            i+=l            
                
        while (change>MissingType and to_delete>0):
            if one>0:
                deleted+=1
                to_delete-=1
                change-=1
                one-=1
            elif two>0:
                deleted+=2
                to_delete-=2             
                change-=1
                two-=1
            else:
                deleted+=3
                to_delete-=3          
                change-=1

        return max(change,MissingType)+deleted+max(0,to_delete)
                
