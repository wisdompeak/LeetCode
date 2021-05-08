class Solution {
    unordered_map<char,string>Map1;
    unordered_map<string,char>Map2;
public:
    bool wordPatternMatch(string pattern, string str) 
    {
        return DFS(0,0,pattern,str);
    }
    
    bool DFS(int x, int y,string &pattern, string &str)
    {
        if (x==pattern.size() && y==str.size())
            return true;
        
        if (Map1.find(pattern[x])!=Map1.end())
        {            
            string s = Map1[pattern[x]];            
            if (y+s.size()>str.size()) return false;
            if (s!=str.substr(y,s.size())) return false;
            return DFS(x+1,y+s.size(),pattern,str);
        }            
        else
        {
            for (int i=y; i<str.size(); i++)
            {
                string s = str.substr(y,i-y+1);
                if (Map2.find(s)!=Map2.end()) continue;
                Map1[pattern[x]]=s;
                Map2[s]=pattern[x];
                if (DFS(x+1,i+1,pattern,str)) 
                    return true;
                Map1.erase(pattern[x]);
                Map2.erase(s);
            }
            return false;
        }            
    }
};
