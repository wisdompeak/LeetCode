class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) 
    {
        int n = envelopes.size();
        sort(envelopes.begin(), envelopes.end());
        vector<int>dp(n,0);
        for (int i=0; i<n; i++)
        {
            dp[i] = 1;
            for (int j=0; j<i; j++)
            {
                if (envelopes[j][0]<envelopes[i][0] && envelopes[j][1]<envelopes[i][1])
                    dp[i] = max(dp[i], dp[j]+1);
            }
        }
        
        int ret = 0;
        for (int i=0; i<n; i++)
            ret = max(ret, dp[i]);
        return ret;
    }
};
