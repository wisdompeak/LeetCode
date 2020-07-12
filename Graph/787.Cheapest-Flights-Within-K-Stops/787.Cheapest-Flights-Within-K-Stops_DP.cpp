class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) 
    {
        auto dp = vector<vector<int>>(K+2, vector<int>(n, INT_MAX/2));
        dp[0][src] = 0;
            
        for (int k=1; k<=K+1; k++)
        {                   
            for (auto flight: flights)
            {
                int a = flight[0];
                int b = flight[1];
                int w = flight[2];                
                dp[k][b] = min(dp[k][b], dp[k-1][b]);
                dp[k][b] = min(dp[k][b], dp[k-1][a]+w);
            }
        }
        
        int ret = dp[K+1][dst];
        
        return (ret>=INT_MAX/2) ? -1 : ret;
    }
};
