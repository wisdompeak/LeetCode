class Solution {
public:
    int lengthOfLongestSubstring(string s) 
    {
        unordered_map<int,int>Map;
        int i=0;
        int result = 0;
        for (int j=0; j<s.size(); j++)
        {
            if (Map.find(s[j])!=Map.end())
                i = max(i,Map[s[j]]+1);
            Map[s[j]] = j;            
            result = max(result,j-i+1);
        }
        return result;
    }
};
