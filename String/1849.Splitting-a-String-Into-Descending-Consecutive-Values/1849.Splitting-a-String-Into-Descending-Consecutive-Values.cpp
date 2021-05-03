typedef long long ll;
class Solution {
public:
    bool splitString(string s) 
    {        
        for (int len=1; len < s.size(); len++)
        {
            ll num = stoll(s.substr(0, len));
            if (num >= 1e10) break;
            if (dfs(s, len, num))
                return true;
        }
        return false;
    }
    
    bool dfs(string&s, int cur, ll num)
    {
        if (cur==s.size()) return true;
        
        for (int len = 1; len + cur <= s.size(); len++)                
        {
            ll num2 = stoll(s.substr(cur, len));
            if (num2 >= 1e10) break;            
            if (num-1 == num2 && dfs(s, cur+len, num2))
                return true;                
        }
        return false;
    }
};
