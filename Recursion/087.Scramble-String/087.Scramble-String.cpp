class Solution {
    int memo[31][31][31];
    int n;
    string s1, s2;
public:
    bool isScramble(string s1, string s2)     
    {
        n = s1.size();
        this->s1 = s1;
        this->s2 = s2;
        
        for (int i=0; i<n; i++)
            for (int j=0; j<n; j++)
                for (int len = 0; len <= n; len++)
                    memo[i][j][len] = -1;
        
        int ret = dfs(0, 0, n);        
        return ret;
    }
    
    bool dfs(int a, int b, int len) 
    {
        if (memo[a][b][len]!= -1)
            return memo[a][b][len];
        
        if (s1.substr(a,len) == s2.substr(b, len))
        {
            memo[a][b][len] = true;
            return true;
        }
            
        if (len==1) 
            return s1[a]==s2[b];
                    
        int flag = false;
        for (int i=1; i<len; i++)
        {
            if (dfs(a,b,i) && dfs(a+i,b+i,len-i))
            {
                flag = true;
                break;
            }
            
            if (dfs(a,b+len-i,i) && dfs(a+i,b,len-i))
            {
                flag = true;
                break;
            }
        }
        
        memo[a][b][len] = flag;
        return flag;
    }
};
