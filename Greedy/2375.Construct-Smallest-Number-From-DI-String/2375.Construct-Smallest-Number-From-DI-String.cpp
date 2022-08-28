class Solution {
public:
    string smallestNumber(string pattern) 
    {
        pattern = "I" + pattern;
        int n = pattern.size();
        
        int mx = 0;
        vector<int>arr;
        
        for (int i=0; i<n; i++)
        {
            int j = i+1;
            while (j<n && pattern[j]=='D')
                j++;
            int count = j-i;
            
            for (int k= mx+count; k>=mx+1; k--)
                arr.push_back(k);
            
            mx = mx+count;
            
            i = j-1;            
        }
        
        string ret;
        for (int i=0; i<n; i++)
            ret.push_back('0'+arr[i]);
        
        return ret;
        
    }
};
