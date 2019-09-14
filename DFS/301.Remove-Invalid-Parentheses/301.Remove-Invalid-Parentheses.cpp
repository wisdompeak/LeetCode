class Solution {
    vector<string>rets;
    int retLen;
public:
    vector<string> removeInvalidParentheses(string s) 
    {
        string curStr = "";
        retLen = -1;
        
        dfs(curStr, s, 0, 0);
        return rets;
    }
    
    void dfs(string curStr, string &s, int i, int count)
    {
        if (count<0) return;
        
        if (i==s.size())
        {
            if (count!=0) return;
                                    
            if (curStr.size() == retLen)
                rets.push_back(curStr);
            else if ((int)curStr.size() > retLen)
            {
                rets.clear();
                rets.push_back(curStr);
                retLen = curStr.size();
            }            
            return;
        }
        
        if (s[i]!='(' && s[i]!=')')
        {
            dfs(curStr+s.substr(i,1), s, i+1, count);
            return;
        }
        
        dfs(curStr+s.substr(i,1), s, i+1, count+(s[i]=='('?1:-1));
        
        if (curStr.size()==0 || curStr.back()!=s[i])
            dfs(curStr, s, i+1, count);
    }
};

