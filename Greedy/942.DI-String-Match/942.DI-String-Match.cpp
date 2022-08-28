class Solution {
public:
    vector<int> diStringMatch(string pattern) 
    {
        pattern = "I" + pattern;
        int n = pattern.size();
        
        int mx = -1;
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
        
        return arr;
    }
};
