class Solution {
public:
    int strStr(string haystack, string needle) 
    {
        int m = needle.size();
        int n = haystack.size();
        
        if (m==0) return 0;
        if (n==0) return -1;
                    
        vector<int>shift(512,0);
        for (int i=0; i<512; i++)
            shift[i]=m+1;
        for (int i=0; i<m; i++)
            shift[needle[i]]=m-i;
        
        int s=0;
        int j;
        while (s<=n-m)
        {
            j=0;

            while (haystack[s+j]==needle[j])
            {
                j++;
                if (j==m) return s;
            }
            s+=shift[haystack[s+m]];
        }
        
        return -1;
    }
};
