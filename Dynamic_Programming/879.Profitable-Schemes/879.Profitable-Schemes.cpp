class Solution {
    int dp[105][105][105];
    int M = 1e9+7;
public:
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) 
    {
        dp[0][0][0] = 1;

        int m = group.size();                
        group.insert(group.begin(), 0);
        profit.insert(profit.begin(), 0);        
        
        for (int i=0; i<m; i++)
            for (int j = 0; j <= n; j++)
                for (int p = 0; p <= minProfit; p++)
                {
                    dp[i+1][j][p] += dp[i][j][p];
                    dp[i+1][j][p] %= M;

                    if (j+group[i+1] <= n)
                    {
                        dp[i+1][j+group[i+1]][min(minProfit, p+profit[i+1])] += dp[i][j][p];
                        dp[i+1][j+group[i+1]][min(minProfit, p+profit[i+1])] %= M;
                    }                        
                }
        
        int ret = 0;
        for (int j = 0; j <= n; j++)                
            ret = (ret + dp[m][j][minProfit]) % M;
        
        return ret;
        
    }
};
