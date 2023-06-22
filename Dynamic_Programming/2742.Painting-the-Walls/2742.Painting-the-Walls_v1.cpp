class Solution {
    int dp[505][505*2];
    int OFFSET = 505;
public:
    int paintWalls(vector<int>& cost, vector<int>& time) 
    {        
        int n = cost.size();
        cost.insert(cost.begin(), 0);
        time.insert(time.begin(), 0);
                
        for (int i=0; i<=n; i++)
            for (int j=-n; j<=n; j++)
            dp[i][j+OFFSET] = INT_MAX/2;
        dp[0][OFFSET] = 0;
        
        for (int i=0; i<n; i++)
            for (int j=-n; j<=n; j++)
            {
                dp[i+1][j-1+OFFSET] = min(dp[i+1][j-1+OFFSET], dp[i][j+OFFSET]);
                
                int jj = min(j+time[i+1], n);
                dp[i+1][jj+OFFSET] = min(dp[i+1][jj+OFFSET], dp[i][j+OFFSET]+cost[i+1]);
            }
        
        int ret = INT_MAX/2;
        for (int j=0; j<=n; j++)
            ret = min(ret, dp[n][j+OFFSET]);       
        
        return ret;
    }
};
