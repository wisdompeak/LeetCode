class Solution {
public:
    int maximumCost(int n, vector<vector<int>>& highways, int k) 
    {
        vector<vector<pair<int,int>>>next(n);
        for (auto highway: highways)
        {
            int a = highway[0], b = highway[1], t = highway[2];
            next[a].push_back({b,t});
            next[b].push_back({a,t});
        }
        
        int ret = -1;
        vector<vector<int>>dp(1<<n, vector<int>(n, INT_MIN));
        for (int i=0; i<n; i++)
            dp[1<<i][i] = 0;
        
        for (int state = 0; state < (1<<n); state++)
        {
            for (int last=0; last<n; last++)
            {
                if (((state>>last)&1)==0) continue;
                for (auto nxt: next[last])
                {
                    auto [j, t] = nxt;
                    if ((state>>j)&1) continue;
                    dp[state+(1<<j)][j] = max(dp[state+(1<<j)][j], dp[state][last]+t);
                }                
                
                if (__builtin_popcount(state)==k+1)
                    ret = max(ret, dp[state][last]);
            }
        }
        
        return ret;
        
    }
};
