class Solution {
    int dp[500001][4];
public:
    int minSideJumps(vector<int>& obstacles) 
    {
        int n = obstacles.size()-1;
        dp[0][1] = 1;
        dp[0][2] = 0;
        dp[0][3] = 1;
        for (int i=1; i<=n; i++)
        {
            int obs = obstacles[i];            
            int minVal = INT_MAX;
            for (int j=1; j<=3; j++)
            {
                if (j==obs)
                    dp[i][j] = INT_MAX;
                else
                    dp[i][j] = dp[i-1][j];                
                minVal = min(minVal, dp[i][j]);
            }

            for (int j=1; j<=3; j++)
            {
                if (j!=obs && dp[i][j]!=minVal)
                    dp[i][j] = minVal+1;
            }
        }

        int ret = INT_MAX;
        for (int j=1; j<=3; j++)
            ret = min(ret, dp[n][j]);
        return ret;
    }
};
