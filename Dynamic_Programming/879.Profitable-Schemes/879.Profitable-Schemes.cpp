class Solution {
public:
    int profitableSchemes(int G, int P, vector<int>& group, vector<int>& profit) 
    {
        auto dp = vector<vector<int>>(G+1, vector<int>(P+1,0));
        int M = 1e9+7;
        
        dp[0][0] = 1;
        
        auto dp_new = dp;
        
        for (int k=0; k<group.size(); k++)
        {
            int x = group[k];
            int y = profit[k];
            
            dp_new = dp;
            
            for (int i = 0; i <= G; i++)
                for (int j = 0; j <= P; j++)
                {
                    if (i+x<=G)
                    {
                        int pp = min(j+y,P);
                        
                        dp_new[i+x][pp] += dp[i][j];
                        dp_new[i+x][pp] %= M;
                    }
                }
            
            dp = dp_new;
        }
        
        int ret = 0;
        for (int i = 0; i <= G; i++)
            ret = (ret+dp[i][P])%M;
        
        return ret;
    }
};
