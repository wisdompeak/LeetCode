class Solution {
public:
    int connectTwoGroups(vector<vector<int>>& cost) 
    {
        int m = cost.size();
        int n = cost[0].size();
        cost.insert(cost.begin(), {0});
        
        vector<vector<int>>dp(m+1, vector<int>(1<<n, INT_MAX/2));
        dp[0][0] = 0;                
        
        vector<vector<int>>cost2(m+1, vector<int>(1<<n));
        for (int i=1; i<=m; i++)
            for (int state = 0; state<(1<<n); state++)
            {
                int sum = 0;
                for (int j=0; j<n; j++)
                {
                    if (((state>>j)&1)==1)
                        sum += cost[i][j];
                }
                cost2[i][state] = sum;
            }
                        
        for (int i=1; i<=m; i++)
        {
            dp[i][0] = INT_MAX/2;
            for (int state = 1; state < (1<<n); state++)
            {
                dp[i][state] = INT_MAX/2;
                for (int subset=state; subset>0; subset=(subset-1)&state)
                {
                    dp[i][state] = min(dp[i][state], dp[i-1][state-subset] + cost2[i][subset]);
                }
                
                int minPath = INT_MAX;
                for (int j=0; j<n; j++)
                    minPath = min(minPath, cost[i][j]);
                dp[i][state] = min(dp[i][state], dp[i-1][state] + minPath);                
            }
            
        }
        
        return dp[m][(1<<n)-1];
        
    }
};
