using LL = long long;
class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) 
    {
        int n = questions.size();
        vector<LL>dp(n+1);
        for (int i=n-1; i>=0; i--)
        {
            int j = i+questions[i][1]+1;            
            dp[i] = max(dp[i+1], (j<n?dp[j]:0) + questions[i][0]);
        }
        return dp[0];
    }
};
