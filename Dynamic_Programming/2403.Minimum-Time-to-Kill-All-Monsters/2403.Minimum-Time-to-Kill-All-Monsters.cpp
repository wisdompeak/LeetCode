using LL = long long;
class Solution {
public:
    long long minimumTime(vector<int>& power) 
    {
        int n = power.size();
        vector<LL>dp(1<<n, LLONG_MAX/2);
        dp[0] = 0;
        for (int state = 1; state < (1<<n); state++)
        {
            int k = __builtin_popcount(state);
            for (int i=0; i<n; i++)
            {
                if ((state>>i)&1)                
                    dp[state] = min(dp[state], dp[state- (1<<i)] + (power[i]-1)/k+1);                
            }
        }
        return dp[(1<<n)-1];        
    }
};
