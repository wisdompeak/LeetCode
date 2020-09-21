class Solution {
    int dp[12][1<<12];
public:
    int connectTwoGroups(vector<vector<int>>& cost) 
    {
        int m = cost.size();
        int n = cost[0].size();

        dp[0][0] = INT_MAX/2;
        for (int state = 1; state < (1<<n); state++)
        {
            int sum = 0;
            for (int j=0; j<n; j++)
            {
                if (((state>>j)&1)==1)
                    sum += cost[0][j];
            }
            dp[0][state] = sum;
        }

        for (int i=1; i<m; i++)
        {
            dp[i][0] = INT_MAX/2;
            for (int state = 1; state < (1<<n); state++)
            {
                dp[i][state] = INT_MAX/2;
                for (int subset=state; subset>0; subset=(subset-1)&state)
                {
                    int sum = 0;
                    for (int j=0; j<n; j++)
                    {
                        if (((subset>>j)&1)==1)
                            sum += cost[i][j];
                    }
                    dp[i][state] = min(dp[i][state], dp[i-1][state-subset]+sum);
                }

                int minPath = INT_MAX;
                for (int j=0; j<n; j++)
                    minPath = min(minPath, cost[i][j]);
                dp[i][state] = min(dp[i][state], dp[i-1][state] + minPath);                                 
            }            
        }

        return dp[m-1][(1<<n)-1];
    }
};
