typedef long long ll;
class Solution {
public:
    bool splitString(string s) 
    {
        int cur = 0;
        while (cur<s.size() && s[cur]=='0')
            cur++;
        
        for (int len=1; cur + len + len-1 <= s.size(); len++)
        {            
            if (dfs(s, cur+len, stoll(s.substr(cur, len)), 1))
                return true;
        }
        return false;
    }
    
    bool dfs(string&s, int cur, ll num, int count)
    {
        if (cur==s.size()) 
        {
           if (count>=2) return true;
           if (count==1 && num==1 && s.back()=='0')  return true;
           return false;
        }
        if (s[cur]=='0') return dfs(s, cur+1, num, count);
        
        for (int len = 1; cur + len <= s.size(); len++)                
        {
            if (len > to_string(num).size()) break;
            if (len < to_string(num).size()-1) continue;
            if (num-1 == stoll(s.substr(cur, len)) && dfs(s, cur+len, num-1, count+1))
                return true;                
        }
        return false;
    }
};
