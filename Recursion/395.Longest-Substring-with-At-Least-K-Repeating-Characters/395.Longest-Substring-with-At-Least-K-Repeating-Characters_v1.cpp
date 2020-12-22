class Solution {
public:
    int longestSubstring(string s, int k) {
        unordered_map<int,int>Map;
        for (int i=0; i<s.size(); i++)
            Map[s[i]]++;
            
        int result = 0;
        for (int i=0; i<s.size(); i++)
        {
            if (Map[s[i]]<k) continue;
            int j = i;
            while (j<s.size() && Map[s[j]]>=k)
                j++;
            if (j-i==s.size())
                return s.size();
            else
                result = max(result, longestSubstring(s.substr(i,j-i),k));
            i = j-1;
        }
        
        return result;
    }
};
