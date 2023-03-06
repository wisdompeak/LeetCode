using LL = long long;
class Solution {
    LL dp[51][1005];
    LL M = 1e9+7;
public:
    int waysToReachTarget(int target, vector<vector<int>>& types) 
    {
        int n = types.size();
        types.insert(types.begin(), {0,0});
        dp[0][0] = 1;
        for (int i=1; i<=n; i++)
            for (int j=0; j<=target; j++)
            {
                for (int k=0; k<=types[i][0]; k++)
                {
                    if (k*types[i][1]>j) break;
                    dp[i][j] += dp[i-1][j- k*types[i][1]];
                    dp[i][j] %= M;
                }
            }
        return dp[n][target];        
    }
};
