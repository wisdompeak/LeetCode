class Solution {
public:
    int minDistance(vector<int>& houses, int K) 
    {
        int n = houses.size();
        sort(houses.begin(), houses.end());
        houses.insert(houses.begin(), INT_MIN);
        vector<vector<int>>dp(n+1, vector<int>(K+1, INT_MAX/2));

        int range[n+1][n+1];
        for (int i=1; i<=n; i++)
            for (int j=i; j<=n; j++)
            {
                int sum = 0;
                for (int k=i; k<=j; k++)
                    sum += abs(houses[k] - houses[(i+j)/2]);
                range[i][j] = sum;
            }

        for (int i=1; i<=n; i++)
            dp[i][1] = range[1][i];

        for (int i=1; i<=n; i++)
            for (int k=2; k<=K; k++)
            {
                for (int j=1; j+1<=i; j++)
                    dp[i][k] = min(dp[i][k],  dp[j][k-1]+range[j+1][i]);
            }

        return dp[n][K];

    }
};
