using LL = long long;
class Solution {
    static bool cmp(vector<int>&a, vector<int>&b)
    {
        return a[1]<b[1];
    }
public:
    long long maxTaxiEarnings(int n, vector<vector<int>>& rides) 
    {
        vector<LL>dp(n+1);
        sort(rides.begin(), rides.end(), cmp);
        int k = 0;
        
        for (int i=1; i<=n; i++)
        {
            dp[i] = dp[i-1];
            while (k<rides.size() && rides[k][1] < i)
                k++;
            while (k<rides.size() && rides[k][1]==i)
            {
                int start = rides[k][0];
                dp[i] = max(dp[i], dp[start]+rides[k][1]-rides[k][0]+rides[k][2]);
                k++;
            }
        }
        return dp[n];
    }
};
