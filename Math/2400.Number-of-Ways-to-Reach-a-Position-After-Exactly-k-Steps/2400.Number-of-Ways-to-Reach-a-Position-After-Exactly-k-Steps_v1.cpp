using LL = long long;
LL M = 1e9+7;
class Solution {
public:
    int numberOfWays(int startPos, int endPos, int k) 
    {        
        LL offset = k;
        
        if (abs(endPos-startPos)>k) return 0;
        
        vector<vector<LL>>dp(k+1, vector<LL>(2*k+10, 0));
        dp[0][0+offset] = 1;
        
        for (int t=1; t<=k; t++)        
            for (int p = -k; p<=k; p++)
            {
                if (p-1 >= -k)
                    dp[t][p+offset] = (dp[t][p+offset] + dp[t-1][p-1+offset]) % M;
                if (p+1 <= k)
                    dp[t][p+offset] = (dp[t][p+offset] + dp[t-1][p+1+offset]) % M;
            }                            
        
        return dp[k][abs(endPos - startPos) + offset];
    }
};
