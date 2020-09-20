class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) 
    {
        vector<int>freq(256,0);
        int n = s.size();
        int j = 0;
        int ret = 0;
        int count = 0;
        for (int i=0; i<n; i++)
        {
            while (j<n && count + (freq[s[j]]+1 == 1) <= k)
            {
                freq[s[j]]++;
                count += (freq[s[j]] == 1);
                j++;
            }
            ret = max(ret, j-i);
            
            freq[s[i]]--;
            count -= (freq[s[i]] == 0);
        }
        return ret;        
    }
};
