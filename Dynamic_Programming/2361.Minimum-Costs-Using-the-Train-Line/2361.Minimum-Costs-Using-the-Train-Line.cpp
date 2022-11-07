using LL = long long;
class Solution {
    LL dp[100005][2];
public:
    vector<long long> minimumCosts(vector<int>& regular, vector<int>& express, int expressCost) 
    {
        int n = regular.size();
        regular.insert(regular.begin(), 0);
        express.insert(express.begin(), 0);
        
        dp[0][0] = 0;
        dp[0][1] = expressCost;
        
        vector<LL>rets;        
        
        for (int i=1; i<=n; i++)
        {
            dp[i][0] = min(dp[i-1][0] + regular[i], dp[i-1][1] + regular[i]);
            dp[i][1] = min(dp[i-1][1] + express[i], dp[i-1][0] + expressCost + express[i]);
                        
            rets.push_back(min(dp[i][0], dp[i][1]));                
        }
        
        return rets;
    }
};
