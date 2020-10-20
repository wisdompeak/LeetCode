class Solution {
    long dp[1001][1001];    
    long sum[1001][1001];
    long M = 1e9+7; 

public:
    int numberOfSets(int n, int K) 
    {
        for (int i=0; i<n; i++)
        {
            dp[i][0] = 1;
            sum[i][0] = i+1;
        }

        for (int i=1; i<n; i++)
            for (int k=1; k<=min(i,K); k++)
            {
                dp[i][k] += sum[i-1][k-1];
                dp[i][k] += dp[i-1][k];
                dp[i][k] %= M;
            
                sum[i][k] = sum[i-1][k] + dp[i][k];
                sum[i][k] %= M;
            }
        return dp[n-1][K]%M;       
    }
};
