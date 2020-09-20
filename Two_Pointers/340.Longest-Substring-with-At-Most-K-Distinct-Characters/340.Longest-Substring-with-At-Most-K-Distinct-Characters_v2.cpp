class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) 
    {
        vector<int>freq(256,0);
        int count = 0;
        int i = 0;
        int ret = 0;
        for (int j=0; j<s.size(); j++)
        {                        
            freq[s[j]]++;
            if (freq[s[j]]==1) count++;
            
            while (count>k)
            {
                freq[s[i]]--;
                if (freq[s[i]]==0)
                    count--;
                i++;
            }
            ret = max(ret, j-i+1);            
        }
        return ret;        
    }
};
