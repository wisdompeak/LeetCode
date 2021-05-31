class Solution {   
    double eps = 1e-8; 
public:
    int minSkips(vector<int>& dist, int speed, int hoursBefore) 
    {
        int n = dist.size();
        dist.insert(dist.begin(), 0);
        vector<vector<double>>dp(n+1, vector<double>(n+1, 1e20));
        dp[0][0] = 0;
        for (int i=1; i<=n-1; i++)
            for (int k=0; k<=i; k++)
            {
                dp[i][k] = ceil(dp[i-1][k] + dist[i]*1.0/speed - eps);
                if (k>=1) 
                    dp[i][k] = min(dp[i][k], dp[i-1][k-1] + dist[i]*1.0/speed);
            }        

        for (int j=0; j<=n; j++)
        {
            dp[n][j] = dp[n-1][j] + dist[n]*1.0/speed;
            if (dp[n][j] <= hoursBefore)
                return j;
        }
        return -1;
    }
};
