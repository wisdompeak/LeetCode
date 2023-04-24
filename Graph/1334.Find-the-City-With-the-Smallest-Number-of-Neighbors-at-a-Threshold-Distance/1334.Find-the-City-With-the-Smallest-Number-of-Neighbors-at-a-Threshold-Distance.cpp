class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) 
    {
        int dp[n][n];
        for (int i=0; i<n; i++)
            for (int j=0; j<n; j++)
            {
                if (i==j) dp[i][j] = 0;
                else dp[i][j] = INT_MAX/3;
            }
        
        
        for (auto edge: edges)
        {
            dp[edge[0]][edge[1]] = edge[2];
            dp[edge[1]][edge[0]] = edge[2];
        }
        
        for (int k=0; k<n; k++)
            for (int i=0; i<n; i++)
                for (int j=0; j<n; j++)
                    dp[i][j] = min(dp[i][j], dp[i][k]+dp[k][j]);
        
        int ret = -1;
        int record = n+1;
        for (int i=0; i<n; i++)
        {
            int count = 0;
            for (int j=0; j<n; j++)
                if (dp[i][j]<=distanceThreshold)
                    count++;
            if (count<=record)
            {
                record = count;
                ret = i;
            }
        }
        return ret;            
    }
};
