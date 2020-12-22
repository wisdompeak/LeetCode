class Solution {
public:
    int longestSubstring(string s, int k) 
    {
        unordered_map<char,int>Map;
        for (auto ch: s)
            Map[ch]++;
        
        int flag = 1;
        for (auto x: Map)
            if (x.second < k)
            {
                flag = 0;
                break;
            }
        if (flag) return s.size();
                
        int ret = 0;
        for (int i=0; i<s.size(); i++)
        {
            if (Map[s[i]]<k) continue;
            int j = i;
            while (j<s.size() && Map[s[j]]>=k)
                j++;
            ret = max(ret, longestSubstring(s.substr(i,j-i), k));
            i = j;
        }
        
        return ret;        
    }
};
