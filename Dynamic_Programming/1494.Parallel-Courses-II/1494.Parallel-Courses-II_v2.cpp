class Solution {
public:
    int minNumberOfSemesters(int n, vector<vector<int>>& dependencies, int k) 
    {
        vector<int>dp(1<<n, INT_MAX/2);
        vector<int>prevState(1<<n, 0);
        vector<int>prevCourse(n,0);

        for (auto x: dependencies)        
            prevCourse[x[1]-1] |= 1<<(x[0]-1);        
                    
        for (int state = 0; state < (1<<n); state++)
        {
            prevState[state] = 0;
            for (int i=0; i<n; i++)
            {
                if ((state>>i) & 1)
                    prevState[state] |= prevCourse[i];
            }
            if (prevState[state]==0 && __builtin_popcount(state)<=k)
                dp[state] = 1;
        }

        dp[0] = 0;
        for (int state = 1; state < (1<<n); state++)        
        {
            for (int subset = state; subset > 0; subset = (subset-1)&state)
            {
                if (__builtin_popcount(state) - __builtin_popcount(subset) <= k && (prevState[state] & subset) == prevState[state])
                {
                    dp[state] = min(dp[state], dp[subset]+1);
                }
            }
        }
        return dp[(1<<n)-1];
    }
};
