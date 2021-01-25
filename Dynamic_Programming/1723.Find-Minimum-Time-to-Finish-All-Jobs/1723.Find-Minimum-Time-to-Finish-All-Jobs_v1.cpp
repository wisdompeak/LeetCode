class Solution {
    int stateTime[4097];
    int dp[13][4096];
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

        for (int state = 1; state < (1<<n); state++)
            dp[0][state] = INT_MAX;
        dp[0][0] = 0;

        for (int i = 1; i<=k; i++)            
            for (int state=0; state<(1<<n); state++)
            {
                dp[i][state] = INT_MAX;
                for (int subset=state; subset>0; subset=(subset-1)&state)
                {
                    dp[i][state] = min(dp[i][state], max(dp[i-1][state-subset],stateTime[subset]));
                }
            }                    
        return dp[k][(1<<n)-1];
    }
};
