class Solution {
public:
    int longestSemiRepetitiveSubstring(string s) 
    {
        int n = s.size();
        int ret = 0;
        int j = 0;
        int count = 0;
        for (int i=0; i<n; i++)
        {                      
            // maintain a valid [i,j) 
            while (j<n && (count + (j>i && s[j]==s[j-1]) < 2))
            {                                                                 
                count += (j>i && s[j]==s[j-1]);
                j++;
            }
            ret = max(ret, j-i);
            
            if (i+1<n && s[i+1]==s[i])
                count--;
        }
        return ret;
    }
};
