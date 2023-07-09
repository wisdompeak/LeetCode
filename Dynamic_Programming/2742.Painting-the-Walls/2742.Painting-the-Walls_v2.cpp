class Solution {
    int dp[505][505];
public:
    int paintWalls(vector<int>& cost, vector<int>& time) 
    {        
        int n = cost.size();
        cost.insert(cost.begin(),0);
        time.insert(time.begin(),0);

        for (int i=0; i<=n; i++)
            for (int j=0; j<=n; j++)
                dp[i][j] = INT_MAX/2;                            
        dp[0][0] = 0;
        
        for (int i=0; i<n; i++)
            for (int j=0; j<=n; j++)
            {
                dp[i+1][min(n, j+time[i+1]+1)] = min(dp[i+1][min(n, j+time[i+1]+1)], dp[i][j]+cost[i+1]);
                dp[i+1][j] = min(dp[i+1][j], dp[i][j]);
            }
        
        return dp[n][n];
    }
};
