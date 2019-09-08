class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        
        auto dp = vector<vector<int>>(N+1, vector<int>(N+1, INT_MAX/2));
        
        for (auto& t: times)
            dp[t[0]][t[1]] = t[2];
        for (int i=1; i<=N; i++)
            dp[i][i] = 0;
        
        for (int k =1; k<=N; k++)
            for (int i=1; i<=N; i++)
                for (int j=1; j<=N; j++)
                    dp[i][j] = min(dp[i][j], dp[i][k]+dp[k][j]);
        
        int ret = 0;
        for (int i=1; i<=N; i++)
            ret = max(ret, dp[K][i]);
        
        return (ret==INT_MAX/2) ? -1: ret;
    }
};
