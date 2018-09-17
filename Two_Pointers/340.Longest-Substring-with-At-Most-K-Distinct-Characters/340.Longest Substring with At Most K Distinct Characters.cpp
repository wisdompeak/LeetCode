class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) 
    {
        unordered_map<char,int>Map;
        int len = 0;
        
        int i=0;
        for (int j=0; j<s.size(); j++)
        {
            Map[s[j]]++;
            
            if (Map.size()<=k)
                len = max(len,j-i+1);
            else while (Map.size()>k)
            {
                Map[s[i]]--;
                if (Map[s[i]]==0)
                    Map.erase(s[i]);
                i++;
            }
        }
        
        return len;
    }
};
