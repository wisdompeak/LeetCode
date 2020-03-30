class Solution {
public:
    int minInsertions(string s) 
    {
        int n = s.size();
        auto dp = vector<vector<int>>(1+n,vector<int>(1+n,0));
        string t = s;
        reverse(t.begin(),t.end());
        s = "#"+s;
        t = "#"+t;
        
        for (int i=1; i<=n; i++)
        {
            dp[i][0] = i;
            dp[0][i] = i;
        }
        
        for (int i=1; i<=n; i++)
            for (int j=1; j<=n; j++)
            {
                if (s[i]==t[j])
                    dp[i][j] = dp[i-1][j-1]+1;
                else
                    dp[i][j] = min(dp[i-1][j]+1, dp[i][j-1]+1);
            }
        return dp[n][n] - n;
    }
};
