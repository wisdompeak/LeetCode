using LL = long long;
class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) 
    {
        int n = questions.size();
        LL ret = 0;
        vector<LL>dp(n, 0);    // dp[i]: the maximum gain before making deicisions on i-th problem
        for (int i=0; i<n; i++)
        {
            int skip = questions[i][1];
            if (i+1<n)
                dp[i+1] = max(dp[i+1], dp[i]);
            if (i+skip+1<n)
                dp[i+skip+1] = max(dp[i+skip+1], dp[i] + questions[i][0]);
            ret = max(ret, dp[i]+questions[i][0]);
        }

        return ret;        
    }
};
