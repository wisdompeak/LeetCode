class Solution {
public:
    int numDistinct(string s, string t) 
    {
        int m = s.size();
        int n = t.size();
        auto dp = vector<vector<long>>(m+1,vector<long>(n+1,0));
        s = "#"+s;
        t = "#"+t;
        
        for (int i=0; i<=m; i++) dp[i][0] = 1;
        
        for (int i=1; i<=m; i++)
            for (int j=1; j<=n; j++)
            {
                if (s[i]==t[j])
                    dp[i][j] += dp[i-1][j-1];
                dp[i][j] += dp[i-1][j];
            }
        
        return dp[m][n];
    }
};
