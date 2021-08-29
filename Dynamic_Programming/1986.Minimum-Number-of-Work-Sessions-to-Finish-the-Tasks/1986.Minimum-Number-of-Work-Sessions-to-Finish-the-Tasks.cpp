class Solution {
public:
    int minSessions(vector<int>& tasks, int sessionTime) 
    {        
        int n = tasks.size();
        vector<int>dp((1<<n), INT_MAX/2);
        for (int state=0; state<(1<<n); state++)
        {
            int sum = 0;
            for (int i=0; i<n; i++)
            {
                if ((state>>i)&1)
                    sum+=tasks[i];
            }
            if (sum<=sessionTime)
                dp[state]=1;
        }
        
        for (int state=1; state<(1<<n); state++)
        {
            for (int subset=state; subset>0; subset=(subset-1)&state)
            {
                dp[state] = min(dp[state], dp[subset]+dp[state-subset]);                                    
            }
        }
        return dp[(1<<n)-1];
        
    }
};
