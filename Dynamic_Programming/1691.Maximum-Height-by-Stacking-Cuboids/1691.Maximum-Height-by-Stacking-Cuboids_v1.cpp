class Solution {
public:
    int maxHeight(vector<vector<int>>& cuboids) 
    {
        int n = cuboids.size();
        vector<array<int,4>>p;
        for (int i=0; i<cuboids.size(); i++)
        {
            auto c = cuboids[i];
            p.push_back({c[0], c[1], c[2], i});
            p.push_back({c[0], c[2], c[1], i});
            p.push_back({c[1], c[0], c[2], i});
            p.push_back({c[1], c[2], c[0], i});
            p.push_back({c[2], c[0], c[1], i});
            p.push_back({c[2], c[1], c[0], i});
        }
        sort(p.begin(), p.end());
        vector<int>dp(6*n);
        for (int i=0; i<6*n; i++)
        {
            dp[i] = p[i][2];
            for (int j=0; j<i; j++)
                if (p[j][0]<=p[i][0] && p[j][1]<=p[i][1] && p[j][2]<=p[i][2] && p[j][3]!=p[i][3])
                    dp[i] = max(dp[i], dp[j]+p[i][2]);
        }

        int ret = 0;
        for (int i=0; i<6*n; i++)
            ret = max(ret, dp[i]);        
        return ret;
    }
};
