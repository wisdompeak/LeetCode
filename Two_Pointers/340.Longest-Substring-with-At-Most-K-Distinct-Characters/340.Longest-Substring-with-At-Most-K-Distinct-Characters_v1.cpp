class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) 
    {
        vector<int>freq(256,0);
        int count = 0;
        int j = 0;
        int ret = 0;
        for (int i=0; i<s.size(); i++)
        {                        
            while (count <= k)
            {
                ret = max(ret, j-i);
                if (j==s.size()) break;                
                freq[s[j]]++;
                if (freq[s[j]]==1)
                    count++;     
                j++;
            }
            
            freq[s[i]]--;
            if (freq[s[i]]==0)
                count--;
        }
        return ret;        
    }
};
