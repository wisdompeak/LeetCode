class Solution {
    int stateTime[4097];
public:
    int minimumTimeRequired(vector<int>& jobs, int k) 
    {
        int n = jobs.size();        
        for (int state = 1; state < (1<<n); state++)
        {
            int sum = 0;
            for (int i=0; i<n; i++)
                if ((state>>i)&1)
                    sum += jobs[i];
            stateTime[state] = sum;
        }

        vector<int>dp(4097, INT_MAX);
        dp[0] = 0;
        for (int t = 0; t<k; t++)
        {
            auto dp_old = dp;
            for (int state=0; state<(1<<n); state++)
            {
                for (int subset=state; subset>0; subset=(subset-1)&state)
                {
                    dp[state] = min(dp[state], max(dp_old[state-subset],stateTime[subset]));
                }
            }            
        }
        return dp[(1<<n)-1];
    }
};
