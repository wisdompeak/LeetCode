class Solution {
public:
    int longestSubstring(string s, int k) 
    {
        if (s=="") return 0;
        
        unordered_map<char,int>Map;
        for (int i=0; i<s.size(); i++)
            Map[s[i]]++;
                
        unordered_set<char>Set;
        for (auto a:Map)
        {
            if (a.second>=k)
                Set.insert(a.first);            
        }        
        if (Set.size()==Map.size())
            return s.size();
        
        int result=0;
        for (int i=0; i<s.size(); i++)
        {
            int i0=i;
            while (i<s.size() && Set.find(s[i])!=Set.end())
                i++;
            result = max(result, longestSubstring(s.substr(i0,i-i0),k));
        }
        
        return result;
            
    }
};
