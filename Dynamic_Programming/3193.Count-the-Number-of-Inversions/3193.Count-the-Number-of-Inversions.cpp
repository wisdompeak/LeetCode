using LL = long long;
class Solution {
    LL dp[305][405];
    LL M = 1e9+7;
public:
    int numberOfPermutations(int n, vector<vector<int>>& requirements) 
    {        
        dp[0][0] = 1;
                
        map<int,LL>Map;
        for (auto req: requirements)
        {
            int end = req[0] + 1;
            int cnt = req[1];
            Map[end] = cnt;
        }

        int cur = 0;
        for (int i=1; i<=n; i++) 
        {
            if (Map.find(i)!=Map.end())
                cur = Map[i];
            
            auto iter = Map.lower_bound(i);
            LL limit = iter->second;
            for (int j=cur; j<=limit; j++)
            {
                for (int k=0; k<=j; k++)
                {
                    if (j-k<=i-1)
                    {
                        dp[i][j] += dp[i-1][k];
                        dp[i][j] %= M;
                    }                        
                }                        
            }
            
            if (Map.upper_bound(i)==Map.end())
            {
                LL ret = dp[i][cur];
                return ret * fact(n-i) % M;                
            }
        }
        return 0;        
    }
    
    LL fact(LL n)
    {
        LL ret = 1;
        for (int i=1; i<=n; i++)
            ret = ret * i % M;
        return ret;
    }
};
