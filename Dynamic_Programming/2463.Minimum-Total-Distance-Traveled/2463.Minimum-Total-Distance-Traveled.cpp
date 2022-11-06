using LL = long long;
class Solution {
    LL dp[101][101];
    LL dist[101][101][101];
public:
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) 
    {
        int m = robot.size();
        int n = factory.size();
        
        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());
        
        for (int i=0; i<n; i++)        
            for (int j=0; j<m; j++)
            {
                LL sum = 0;
                for (int k=j; k<m; k++)
                {
                    sum += abs(factory[i][0]-robot[k]);
                    dist[i][j][k] = sum;
                }
            }
        
        dp[0][0] = 0;
        for (int j=1; j<=m; j++)
        {
            if (j<=factory[0][1])
                dp[0][j] = dist[0][0][j-1];
            else
                dp[0][j] = LLONG_MAX/2;
        }            
                
        for (int i=1; i<n; i++)
            for (int j=1; j<=m; j++)
            {                
                dp[i][j] = dp[i-1][j];
                for (int k=1; k<=min(j,factory[i][1]); k++)                
                    dp[i][j] = min(dp[i][j], dp[i-1][j-k] + dist[i][j-k][j-1]);
            }
        
        return dp[n-1][m];
    }        
};
