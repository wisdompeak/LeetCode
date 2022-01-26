using LL = long long;
class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        vector<vector<LL>> dp(n, vector<LL>(2));        
        dp[0][1] = questions[0][0];

        vector<LL>base(n);
        LL diff = 0;
        
        LL maxPre = 0;
        for (int i = 0; i < n; ++i)
        {
            diff = max(diff, base[i]);
            dp[i][1] = diff + questions[i][0];

            int skip = questions[i][1];
            if (i+1<n)
                dp[i+1][0] = max(dp[i+1][0], max(dp[i][0], dp[i][1]));
            if (i+skip+1<n)
                base[i+skip+1] = max(base[i+skip+1], dp[i][1]);
        }

        return max(dp[n-1][0], dp[n-1][1]);
    }
};
