using LL = long long;
class Solution {
public:
    long long numberOfPowerfulInt(long long start, long long finish, int limit, string s) 
    {
        return helper(to_string(finish), limit, s) - helper(to_string(start-1), limit, s);        
    }
    
    LL helper(string a, int limit, string s)
    {
        if (a.size() < s.size()) return 0;
        return dfs(a, s, limit, 0, true);
    }
    
    LL dfs(string a, string s, int limit, int k, bool same)
    {                
        if (a.size() - k == s.size())
        {
            int len = s.size();
            if (!same || a.substr(a.size()-len, len) >= s) return 1;
            else return 0;
        }
        
        LL ret = 0;
        if (!same)
        {
            int d = a.size()-s.size()-k;
            ret = pow(1+limit, d);     
        }
        else
        {
            for (int i=0; i<=limit; i++)
            {
                if (i > a[k]-'0') break;
                else if (i == a[k]-'0') 
                    ret += dfs(a, s, limit, k+1, true);
                else 
                    ret += dfs(a, s, limit, k+1, false);                    
            }
        }
        return ret;        
    }
};
