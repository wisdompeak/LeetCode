class Solution {
    int dp[105][25][105];
public:
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) 
    {
        houses.insert(houses.begin(), 0);
        cost.insert(cost.begin(), {0});

        for (int i=0; i<=m; i++)
            for (int j=0; j<=n; j++)
                for (int k=0; k<=target; k++)
                    dp[i][j][k] = INT_MAX/2;

        for (int j=0; j<=n; j++)
            dp[0][j][0] = 0;

        for (int i=1; i<=m; i++)
        {
            if (houses[i]!=0)
            {
                int j = houses[i];                
                for (int jj=1; jj<=n; jj++)
                    for (int k=1; k<=target; k++)
                    {                        
                        if (j==jj)
                            dp[i][j][k] = min(dp[i][j][k], dp[i-1][jj][k]);
                        else
                            dp[i][j][k] = min(dp[i][j][k], dp[i-1][jj][k-1]);                        
                    }
            }
            else
            {
                for (int j=1; j<=n; j++)
                    for (int k=1; k<=target; k++)
                    {                        
                        for (int jj=1; jj<=n; jj++)
                        {
                            if (j==jj)
                                dp[i][j][k] = min(dp[i][j][k], dp[i-1][jj][k] + cost[i][j-1]);
                            else
                                dp[i][j][k] = min(dp[i][j][k], dp[i-1][jj][k-1] + cost[i][j-1]);
                        }
                    }
            }    
        }

        int ret = INT_MAX/2;
        for (int j=1; j<=n; j++)
            ret = min(ret, dp[m][j][target]);
        if (ret==INT_MAX/2)
            return -1;
        else
            return ret;
    }
};
