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
        int k = 1;
        while (k<=N && p[k]=='*')
        {
            dp[0][k] = 1;
            k++;
        }

        for (int j=1; j<=N; j++)
            for (int i=1; i<=M; i++)
            {
                if (p[j]=='?')
                    dp[i][j] = dp[i-1][j-1];
                else if (p[j]=='*')
                    dp[i][j] = dp[i][j-1]||dp[i-1][j];
                else if (s[i]==p[j])
                    dp[i][j] = dp[i-1][j-1];
            }
        return dp[M][N];
    }
};
