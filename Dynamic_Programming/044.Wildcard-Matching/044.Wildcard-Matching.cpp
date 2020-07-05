class Solution {
public:
    bool isMatch(string &s, string &p) 
    {
        int M = s.size();
        int N = p.size();
        s="0"+s;
        p="0"+p;
        auto dp = vector<vector<int>>(M+1,vector<int>(N+1,0));        

        dp[0][0] = 1;
        for (int j=1; j<=N; j++)
        {
            if (p[j]!='*') break;
            dp[0][j] = 1;
        }
        
        for (int i=1; i<=M; i++)
            for (int j=1; j<=N; j++)
            {
                if (p[j]=='?')
                    dp[i][j] = dp[i-1][j-1];
                else if (p[j]=='*')
                {
                    // for (int k=0; k<=i; k++)
                    //     if (dp[k][j-1]==1) dp[i][j]=1;
                    dp[i][j] = dp[i][j-1]||dp[i-1][j];
                }
                else if (s[i]==p[j])
                    dp[i][j] = dp[i-1][j-1];
            }
        
        return dp[M][N];
    }
};
