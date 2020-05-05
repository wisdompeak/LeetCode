class Solution {
public:
    int numberOfWays(int num_people) 
    {
        int n = num_people;
        vector<long long>dp(n+1,0);        
        dp[0] = 1;
        dp[2] = 1;
        int M = 1e9+7;
        
        for (int i=4; i<=n; i+=2)
        {
            for (int j=0; j<=i-2; j++)
            {
                dp[i] += dp[j]*dp[i-2-j]%M;
                dp[i] %= M;
            }            
        }
        return dp[n];
    }
};
