class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) 
    {
        vector<int>dp(n,INT_MAX/2);
        dp[src] = 0;
            
        for (int k=0; k<K+1; k++)
        {
            auto dp_temp = dp;
            for (auto flight: flights)
            {
                int a = flight[0];
                int b = flight[1];
                int w = flight[2];
                dp[b] = min(dp[b], dp_temp[a]+w);
            }
            //cout<<k<<" "<<dp[dst]<<endl;
        }
        
        if (dp[dst]>=INT_MAX/2)
            return -1;
        else
            return dp[dst];
    }
};
