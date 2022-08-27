class Solution {
public:
    int secondsToRemoveOccurrences(string s) 
    {
        int n = s.size();        
        int ret = 0;
        int count = 0;
        for (int i=0; i<n; i++)
        {
            if (s[i]=='0') 
                count++;
            else if (count > 0)
                ret = max(ret+1, count);            
        }
        return ret;        
    }
};
