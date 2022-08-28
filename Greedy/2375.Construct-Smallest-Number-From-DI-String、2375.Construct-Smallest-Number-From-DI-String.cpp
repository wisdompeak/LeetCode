class Solution {
public:
    string smallestNumber(string pattern) 
    {
        pattern = "I" + pattern;
        int n = pattern.size();
        vector<int>arr;
        int mx = 0;
        
        for (int i=0; i<n; i++)
        {
            int j = i+1;
            while (j<n && pattern[j]=='D')
                j++;
            int count = j-i;
                
            for (int k=mx+count; k>=mx+1; k--)
                arr.push_back(k);
            
            mx = mx+count;
            
            i = j-1;
        }        
        
        int mn = INT_MAX;
        for (int i=0; i<n; i++)
            mn = min(mn, arr[i]);
        
        int diff = 1-mn;
        
        string ret;
        for (int i=0; i<n; i++)
            ret.push_back('0'+arr[i]+diff);
        
        return ret;
        
    }
};
