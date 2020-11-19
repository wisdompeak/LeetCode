class Solution {
public:
    bool canConvertString(string s, string t, int k) 
    {
        if (s.size()!=t.size()) return false;
        int n = s.size();
        vector<int>times(27);
        
        for (int i=0; i<n; i++)
        {
            times[(t[i]-s[i]+26)%26] += 1;
        }
        times[26] = times[0];
        
        int maxNum = 0;
        int loop = 0;
        for (int i=1; i<26; i++)
        {
            if (times[i] >= loop)
            {
                loop = times[i];
                maxNum = i;
            }
        }
        
        return (loop-1)*26+maxNum <=k;            
    }
};
