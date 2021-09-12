class Solution {    
public:
    int lp(string&s, int state)
    {           
        string t;
        for (int i=0; i<s.size(); i++)
        {
            if ((state>>i)&1)
                t.push_back(s[s.size()-1-i]);
        }
                
        int n = t.size();          
        vector<vector<int>>dp(n, vector<int>(n));
        for (int i=0; i<n; i++)
            dp[i][i] = 1;
        for (int len=2; len<=n; len++)
            for (int i=0; i+len-1<n; i++)
            {
                int j = i+len-1;
                if (t[i]==t[j])
                    dp[i][j] = dp[i+1][j-1]+2;
                else
                    dp[i][j] = max(dp[i][j-1], dp[i+1][j]);
            }        
       
        return dp[0][n-1];
    }
    
    
    int maxProduct(string s) 
    {
        int n = s.size();
        int all = (1<<n)-1;
        int ret = 0;
        for (int subset=1; subset<(1<<n)-1; subset++)
            ret = max(ret, lp(s, all-subset)*lp(s, subset));
        return ret;
    }
};
