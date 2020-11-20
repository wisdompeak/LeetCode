class Solution {
public:
    bool canConvertString(string s, string t, int k) 
    {
        if (s.size()!=t.size()) return false;
        int n = s.size();
        vector<int>count(26);
        
        for (int i=0; i<n; i++)        
            count[(t[i]-s[i]+26)%26] += 1;                
        
        int ret = 0;
        for (int i=1; i<26; i++)        
        {
            if (count[i]>=1)
                ret = max(ret, (count[i]-1)*26+i);        
        }
        return ret<=k;
    }
};
