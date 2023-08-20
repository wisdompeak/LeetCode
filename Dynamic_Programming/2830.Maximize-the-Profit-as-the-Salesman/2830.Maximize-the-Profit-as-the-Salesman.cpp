class Solution {
    int dp[100005];
public:
    int maximizeTheProfit(int n, vector<vector<int>>& offers) 
    {
        
        unordered_map<int, vector<pair<int,int>>>Map;
        for (auto& offer:offers)        
            Map[offer[1]+1].push_back({offer[0]+1, offer[2]});        
        
        for (int i=1; i<=n; i++)
        {
            dp[i] = dp[i-1];
            for (auto& [start, val]: Map[i])
                dp[i] = max(dp[i], dp[start-1] + val);            
        }
        
        return dp[n];
        
    }
};
