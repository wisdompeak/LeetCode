class Solution {
    int count = 0;
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) 
    {
        vector<int>freq(256,0);        
        int n = s.size();
        int j = 0;
        int ret = 0;
        for (int i=0; i<s.size(); i++)
        {                                     
            while (j<n && getCount(freq, s[j]) <= k)
            {
                freq[s[j]]++;
                count += (freq[s[j]]==1);
                j++;                
            }
                
            ret = max(ret, j-i);
                        
            freq[s[i]]--;
            count -= (freq[s[i]]==0);
        }
        return ret;        
    }
    
    int getCount(vector<int>&freq, char ch)
    {                
        if (freq[ch]==0)
            return count+1;
        else
            return count;
    }
};
