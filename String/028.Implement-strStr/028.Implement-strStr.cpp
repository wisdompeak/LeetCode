class Solution {
public:
    int strStr(string haystack, string needle) 
    {
        int n=haystack.size();
        int m=needle.size();        
        vector<int>prefix=createPrefix(needle);
        
        if (m==0) return 0;
        if (n==0) return -1;        
        
        int j=-1;
        for (int i=0; i<n; i++)
        {
            while (j>=0 && needle[j+1]!=haystack[i])
                j=prefix[j];            
            if (needle[j+1]==haystack[i])
                j++;            
            if (j==m-1)
                return i-j;                
        }
        
        return -1;
    }
    
    vector<int> createPrefix(string needle)
    {
        int m=needle.size();
        vector<int>Prefix(m,-1);
        
        int j=-1;
        for (int i=1; i<m; i++)
        {
            while (j>=0 && needle[j+1]!=needle[i])
                j=Prefix[j];            
            if (needle[j+1]==needle[i])
                j++;            
            Prefix[i]=j;            
        }
        
        return Prefix;        
    }
};
