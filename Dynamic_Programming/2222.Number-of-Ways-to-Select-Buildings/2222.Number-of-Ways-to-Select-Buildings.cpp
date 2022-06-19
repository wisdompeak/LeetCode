using LL = long long;
class Solution {
    LL dp[100005][4][2];    
public:
    long long numberOfWays(string s) 
    {
        int n = s.size();
        s = "#"+s;
        
        dp[0][0][0] = 1;
        dp[0][0][1] = 1;
                
        for (int i=1; i<=n; i++)
            for (int j=0; j<=3; j++)
                for (int k=0; k<2; k++)
                {
                    dp[i][j][k] = dp[i-1][j][k];

                    if (j>=1 && k==(s[i]-'0'))
                        dp[i][j][k] += dp[i-1][j-1][1-k];                    
                }
        
        return dp[n][3][0] + dp[n][3][1];        
    }
};
