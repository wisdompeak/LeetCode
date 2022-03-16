class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) 
    {
        vector<vector<int>>dp(n, vector<int>(K+2, INT_MAX/2));
        dp[src][0] = 0;
        int ret = INT_MAX/2;

        for (int j=1; j<=K+1; j++)
            for (auto flight: flights)
            {
                int a = flight[0], b = flight[1], p = flight[2];
                dp[b][j] = min(dp[b][j], dp[a][j-1]+p);
                if (b==dst) ret = min(ret, dp[b][j]);
            }

        return ret >= INT_MAX/2 ? -1 : ret;
    }
};
