class Solution {
    unordered_map<char, string>Map1;
    unordered_map<string, char>Map2;   
    bool visited[20][20];
public:
    bool wordPatternMatch(string pattern, string s) 
    {
        return dfs(0,0,pattern,s);        
    }
    
    bool dfs(int x, int y, string& pattern, string& s)
    {
        if (x==pattern.size()) return y==s.size();
        
        char ch = pattern[x];
        if (Map1.find(ch)!=Map1.end())
        {
            string t = Map1[ch];
            if (y + t.size() > s.size()) return false;            
            if (s.substr(y, t.size()) != t) return false;
            return dfs(x+1, y+t.size(), pattern, s);
        }
        else
        {
            for (int i=y; i<s.size(); i++)
            {
                string t = s.substr(y, i-y+1);
                if (Map2.find(t)!=Map2.end()) continue;
                Map1[ch] = t;
                Map2[t] = ch;
                if (dfs(x+1, y+t.size(), pattern, s))
                    return true;
                Map1.erase(ch);
                Map2.erase(t);
            }
            return false;
        }
    }
};
