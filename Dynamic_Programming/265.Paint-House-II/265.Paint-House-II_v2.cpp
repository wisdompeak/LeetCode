class Solution {
public:
    int minCostII(vector<vector<int>>& costs) 
    {
        int N = costs.size();
        if (N==0) return 0;
        int K = costs[0].size();
                
        auto dp = vector<vector<int>>(N,vector<int>(K,0));
        for (int k=0; k<K; k++)
            dp[0][k] = costs[0][k];
        
        for (int i=1; i<N; i++)
        {
            vector<pair<int,int>>temp;
            for (int k=0; k<K; k++)
                temp.push_back({dp[i-1][k],k});
            sort(temp.begin(),temp.end());                
                
            for (int k=0; k<K; k++)
            {
                if (k!=temp[0].second)
                    dp[i][k] = temp[0].first + costs[i][k];
                else
                    dp[i][k] = temp[1].first + costs[i][k];
            }
        }
        
        int ret = INT_MAX;
        for (int k=0; k<K; k++)
            ret = min(ret, dp[N-1][k]);
        return ret;
    }
};
