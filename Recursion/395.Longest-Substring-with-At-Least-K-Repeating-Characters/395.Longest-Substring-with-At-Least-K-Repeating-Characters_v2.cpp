class Solution {
public:
    int helper(string& s, int t, int k)
    {
        int j = 0;
        unordered_map<char, int>Map;
        int count = 0;
        int ret = 0;
        for (int i=0; i<s.size(); i++)
        {
            while (j<s.size() && Map.size() <= t)
            {
                Map[s[j]]++;
                if (Map[s[j]]==k)
                    count++;
                j++;

                if (Map.size()==t && count == t)
                    ret = max(ret, j-i);
            }
            
            Map[s[i]]--;
            if (Map[s[i]]==k-1)
                count--;
            if (Map[s[i]]==0)
                Map.erase(s[i]);
        }
        return ret;
    }

    int longestSubstring(string s, int k) 
    {
        int ret = 0;
        for (int t=1; t<=26; t++)
            ret = max(ret, helper(s, t, k));
        return ret;
    }
};
