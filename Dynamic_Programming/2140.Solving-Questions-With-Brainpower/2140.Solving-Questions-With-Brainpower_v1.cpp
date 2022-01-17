using LL = long long;
class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) 
    {
        int n = questions.size();
        vector<LL>dp(n+1, 0);    
        for (int i=n-1; i>=0; i--)
        {
            int skip = questions[i][1];
            dp[i] = max(dp[i+1], dp[min(i+skip+1, n)] + questions[i][0]);
        }
        return dp[0];        
    }
};
