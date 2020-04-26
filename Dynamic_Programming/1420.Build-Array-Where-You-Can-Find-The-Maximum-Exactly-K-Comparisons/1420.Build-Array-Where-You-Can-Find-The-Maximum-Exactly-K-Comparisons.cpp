class Solution {
public:
    int numOfArrays(int n, int m, int k) 
    {
        int K = k;
        long dp[n][K+1][m+1];
        long M = 1e9+7;
        
        for (int i=0; i<n; i++)
            for (int k=0; k<=K; k++)
                for (int j=1; j<=m; j++)
                    dp[i][k][j] = 0;
        
        for (int j=1; j<=m; j++)
        dp[0][1][j] = 1;
        
        for (int i=1; i<n; i++)
            for (int k=1; k<=K; k++)
                for (int j=1; j<=m; j++)
                {   
                    dp[i][k][j] = 0;
                    for (int t=1; t<j; t++)
                        dp[i][k][j] = (dp[i][k][j] + dp[i-1][k-1][t])%M;
                    
                    dp[i][k][j] = (dp[i][k][j] + dp[i-1][k][j] * j)%M;                                        
                }
        
        
        long ret = 0;
        for (int j=1; j<=m; j++)
            ret = (ret + dp[n-1][k][j])%M;
        
        return ret;
    }
};
