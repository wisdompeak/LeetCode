class Solution {
public:
    int numberWays(vector<vector<int>>& hats) 
    {
        int n = hats.size();
        unordered_map<int,vector<int>>Map;
        for (int i=0; i<hats.size(); i++)
            for (int j=0; j<hats[i].size(); j++)
                Map[hats[i][j]].push_back(i);
        
        vector<long>dp(1<<n, 0);
        dp[0] = 1;
        for (int p: Map[1])
            dp[1<<p] = 1;
        long M = 1e9+7;
        
        for (int i=2; i<=40; i++)
        {
            auto dp2=dp;
            
            for (int set = 0; set<(1<<n); set++)
            {
                for (int p: Map[i])
                {
                    if (((set>>p)&1)==0)
                    {
                        dp2[set+(1<<p)] += dp[set];
                        dp2[set+(1<<p)]%=M;
                    }
                }
            }
            
            dp = dp2;
        }
        
        return dp[(1<<n)-1];                
    }
};
