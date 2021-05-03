typedef long long ll;
class Solution {
public:
    bool splitString(string s) 
    {
        ll num = 0;
        for (int i = 0; i < s.size(); i++)
        {   num  = num*10 + (s[i] - '0');
            if (num > 1e11) break;
            if (dfs(s, i+1, num, 1))
                return true;
        }
        return false;
    }
    
    bool dfs(string&s, int cur, ll num, int count)
    {
        if (cur==s.size())  return count>=2;
                
        ll k = 0;
        for (int i=cur; i<s.size(); i++)                
        {
            k = k*10 + (s[i]-'0');
            if (k > 1e10) break;
            if (k > num) break;            
            if (num-1 == k && dfs(s, i+1, k, count+1))
                return true;                
        }
        return false;
    }
};
