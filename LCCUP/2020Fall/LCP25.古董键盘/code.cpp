class Solution {
    long dp[131][27];
public:
    int keyboard(int k, int n) 
    {
        long comb[131][131];  
        long M = 1e9+7;

        for (int j=0; j<=26; j++)
            dp[0][j] = 1;

        for (int i = 0; i <= n; ++i) 
        {
            comb[i][i] = comb[i][0] = 1;    
            if (i==0) continue;        
            for (int j = 1; j <= min(n, k); ++j) 
            {
                comb[i][j] = comb[i - 1][j - 1] + comb[i - 1][j];
                comb[i][j] %= M;
            }
        }

        for (int i=1; i<=n; i++)
            for (int j=1; j<=26; j++)
            {                
                for (int t = 0; t <= min(i, k); t++)
                {
                    dp[i][j] += dp[i-t][j-1] * comb[i][t];
                    dp[i][j] %= M;
                }                    
            }
        return dp[n][26];
    }
};
