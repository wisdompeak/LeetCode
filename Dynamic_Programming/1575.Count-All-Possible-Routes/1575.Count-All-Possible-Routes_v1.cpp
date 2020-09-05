class Solution {
    long dp[201][100];
public:    
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) 
    {
        int n = locations.size();
        dp[fuel][start] = 1;
        long M = 1e9+7;
        long ret = 0;
        
        for (int f=fuel; f>=0; f--)
            for (int c = 0; c<n; c++)
            {
                if (c==finish) ret = (ret+dp[f][c])%M;
                for (int d = 0; d<n; d++)
                {
                    if (d==c) continue;                  
                    int gas = abs(locations[d]-locations[c]);
                    if (f-gas >= 0)
                        dp[f-gas][d] = (dp[f-gas][d]+dp[f][c])%M;
                }
            }
        
        return ret;
    }
};
