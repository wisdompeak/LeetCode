class Solution {
    long dp0[1001][1001];    
    long dp1[1001][1001];    
    long sum0[1001][1001];
    long sum1[1001][1001];
    long M = 1e9+7; 

public:
    int numberOfSets(int n, int K) 
    {
        for (int i=0; i<n; i++)
        {
            dp0[i][0] = 1;
            sum0[i][0] = i+1;
        }

        for (int i=1; i<n; i++)
            for (int k=1; k<=min(i,K); k++)
            {
                dp1[i][k] = sum0[i-1][k-1] + sum1[i-1][k-1];
                dp0[i][k] = sum1[i-1][k];
            
                sum0[i][k-1] = sum0[i-1][k-1] + dp0[i][k-1];
                sum1[i][k] = sum1[i-1][k] + dp1[i][k];

                sum0[i][k-1] %= M;
                sum1[i][k] %= M;
            }
        return (dp0[n-1][K]+dp1[n-1][K])%M;       
    }
};
