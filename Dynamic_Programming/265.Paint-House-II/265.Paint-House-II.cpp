class Solution {
public:
    int minCostII(vector<vector<int>>& costs) 
    {
        int N = costs.size();
        if (N==0) return 0;
        int K = costs[0].size();
                
        auto dp = vector<vector<int>>(N,vector<int>(K,0));
        
        int Min1Color=-1, Min2Color=-1;
        
        for (int i=0; i<N; i++)
        {
            int Min1 = INT_MAX, Min2 = INT_MAX;
            int NewMin1Color, NewMin2Color;
         
            for (int j=0; j<K; j++)
            {
                if (i==0)
                {
                    dp[i][j] = costs[0][j];
                }
                else
                {
                    if (j==Min1Color)
                        dp[i][j] = dp[i-1][Min2Color]+costs[i][j];
                    else
                        dp[i][j] = dp[i-1][Min1Color]+costs[i][j];
                }
            
                if (dp[i][j]<Min1)
                {
                    Min2 = Min1;
                    NewMin2Color = NewMin1Color;
                    Min1 = dp[i][j];
                    NewMin1Color = j;
                }
                else if (dp[i][j]<Min2)
                {
                    Min2 = dp[i][j];
                    NewMin2Color = j;
                }
            }
            
            Min1Color = NewMin1Color;
            Min2Color = NewMin2Color;            
        }        
        return dp[N-1][Min1Color];
    }
};
