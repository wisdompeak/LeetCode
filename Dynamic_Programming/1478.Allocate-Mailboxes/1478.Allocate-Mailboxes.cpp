class Solution {
public:
    int minDistance(vector<int>& houses, int k) 
    {
        sort(houses.begin(), houses.end());
        
        int n = houses.size();
        int range[n][n];
        for (int i=0; i<n; i++)
            for (int j=i; j<n; j++)
            {
                int sum = 0;
                for (int k=i; k<=j; k++)
                    sum += abs(houses[(i+j)/2]-houses[k]);
                range[i][j] = sum;
            }
        
        int K = k;
        int dp[n][K+1];
        for (int i=0; i<n; i++)
            dp[i][1] = range[0][i];
        
        
        for (int i=0; i<n; i++)
            for (int k=2; k<=K; k++)
            {
                dp[i][k] = INT_MAX/3;
                for (int j=0; j<i; j++)
                    dp[i][k] = min(dp[i][k], dp[j][k-1]+range[j+1][i]);
            }
        
        return dp[n-1][K];
        
    }
};
