class Solution {    
    int dist[10][10];
public:
    int assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) 
    {
        int m = workers.size();
        int n = bikes.size();
        
        for (int i=0; i<m; i++)
            for (int j=0; j<n; j++)
            {
                int x1 = workers[i][0];
                int y1 = workers[i][1];
                int x2 = bikes[j][0];
                int y2 = bikes[j][1];
                dist[i][j] = abs(x1-x2)+abs(y1-y2);
            }
        
        vector<int>dp(1<<m, INT_MAX/2);
        vector<int>dp2;
        dp[0] = 0;
        for (int j=0; j<n; j++)
        {
            dp2 = dp;
            for (int state = 0; state < (1<<m); state++)
            {
                for (int i=0; i<m; i++)
                {
                    if ((state >> i) &1)
                        dp[state] = min(dp[state], dp2[state- (1<<i)] + dist[i][j]);                    
                }                
            }
        }
        
        return dp[(1<<m)-1];
    }
};
