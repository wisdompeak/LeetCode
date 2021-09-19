using LL = long long;
class Solution {
public:
    long long maxTaxiEarnings(int n, vector<vector<int>>& rides) 
    {
        vector<LL>dp(n+1);
        unordered_map<int, vector<pair<int,int>>>Map; // endTime -> {startTime, gain}
        for (auto ride: rides)
            Map[ride[1]].push_back({ride[0], ride[1]-ride[0]+ride[2]});
        
        for (int i=1; i<=n; i++)
        {
            dp[i] = dp[i-1];
            for (auto ride: Map[i])
            {
                int start = ride.first, gain = ride.second;
                dp[i] = max(dp[i], dp[start] + ride.second);
            }           
        }
        return dp[n];
    }
};
