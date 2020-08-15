class Solution {
public:
    vector<int> mostSimilar(int n, vector<vector<int>>& roads, vector<string>& names, vector<string>& targetPath) 
    {
        int T= targetPath.size();
        vector<int>dp(n,0);
        auto prev = vector<vector<int>>(T, vector<int>(n,-1));
        
        vector<vector<int>>next(n);
        for (auto road : roads)
        {
            next[road[0]].push_back(road[1]);
            next[road[1]].push_back(road[0]);
        }
        
        for (int t=0; t<T; t++)
        {
            auto dp_temp = dp;            
            for (int i=0; i<n; i++)
            {
                dp[i] = INT_MAX/2;
                for (int j: next[i])                    
                {
                    if (dp[i] > dp_temp[j] + (names[i]!=targetPath[t]))
                    {
                        dp[i] = dp_temp[j] + (names[i]!=targetPath[t]);
                        prev[t][i] = j;
                    }                    
                }                
            }
        }
        
        int dist = INT_MAX/2;
        int start;
        for (int i=0; i<n; i++)
        {
            if (dist > dp[i])
            {
                dist = dp[i];
                start = i;
            }
        }
            
        vector<int>rets;
        for (int t=T-1; t>=0; t--)
        {
            rets.push_back(start);
            start = prev[t][start];
        }
        reverse(rets.begin(), rets.end());
        
        return rets;
    }
};
