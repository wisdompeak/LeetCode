class Solution {
    int ret = 0;    
    unordered_set<string>Set;
public:
    int maxUniqueSplit(string s) 
    {
        int n = s.size();
        dfs(s,0,0);
        return ret;
    }
    void dfs(string&s, int cur, int len)
    {
        if (cur==s.size())
        {
            ret = max(ret, len);
            return;
        }
        if (s.size()-cur + len <= ret)
            return;

        for (int i=cur; i<s.size(); i++)
        {
            if (Set.find(s.substr(cur, i-cur+1))==Set.end())
            {
                Set.insert(s.substr(cur, i-cur+1));
                dfs(s, i+1, len+1);
                Set.erase(s.substr(cur, i-cur+1));
            }            
        }
    }
};
