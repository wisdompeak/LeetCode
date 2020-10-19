class Solution {
    long dp0[1001][1001];    
    long dp1[1001][1001];    
    long sum0[1001][1001];
    long sum1[1001][1001];
    long M = 1e9+7;    
public:
    int numberOfSets(int n, int K) 
    {                
        dp0[1][0] = 1;        
        sum0[1][0] = 1;
        
        for (int i=2; i<=n; i++)
        {
            dp0[i][0] = 1;
            sum0[i][0] = sum0[i-1][0]+1;
        }
            
        
        for (int i=2; i<=n; i++)
            for (int k=1; k<=K; k++)
            {
                dp0[i][k] = sum1[i-1][k];
                dp1[i][k] = (sum0[i-1][k-1]+sum1[i-1][k-1])%M;
                sum0[i][k] = sum0[i-1][k]+dp0[i][k];
                sum1[i][k] = sum1[i-1][k]+dp1[i][k];
                                
                sum0[i][k] %= M;
                sum1[i][k] %= M;
            } 
        
        return (dp0[n][K]+dp1[n][K])%M;        
    }
};
