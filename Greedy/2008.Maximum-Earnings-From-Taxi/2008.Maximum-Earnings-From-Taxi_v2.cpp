using LL = long long;
class Solution {
    static bool cmp(vector<int>&a, vector<int>&b)
    {
        return a[1]<b[1];
    }
public:
    long long maxTaxiEarnings(int n, vector<vector<int>>& rides) 
    {        
        int m = rides.size();
        rides.push_back({0,0,0});        
        vector<LL>dp(m+1);
        sort(rides.begin(), rides.end(), cmp);
        
        vector<int>times;
        for (auto r: rides) times.push_back(r[1]);
        
        for (int i=1; i<=m; i++)
        {
            dp[i] = dp[i-1];
            int start = rides[i][0];
            auto iter = upper_bound(times.begin(), times.end(), start);
            if (iter!=times.begin())
            {
                int j = prev(iter)-times.begin();
                dp[i] = max(dp[i], dp[j]+rides[i][1]-rides[i][0]+rides[i][2]);
            }
                
        }
        return dp[m];
    }
};
