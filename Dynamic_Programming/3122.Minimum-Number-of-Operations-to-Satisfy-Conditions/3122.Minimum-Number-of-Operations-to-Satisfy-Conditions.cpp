class Solution {
    int dp[1005][10];
public:
    int minimumOperations(vector<vector<int>>& grid) 
    {
        int m = grid.size(), n = grid[0].size();
        
        for (int i=0; i<n; i++)
            for (int p=0; p<=9; p++)
            {
                dp[i][p] = INT_MAX/2;
                
                int count = 0;
                for (int a=0; a<m; a++)
                    count += (grid[a][i]!=p);               
                
                if (i==0)
                {
                    dp[i][p] = count;
                }                    
                else
                {
                    for (int q=0; q<=9; q++)
                    {
                        if (q==p) continue;
                        dp[i][p] = min(dp[i][p], dp[i-1][q]+count);
                    }                    
                }
            }
        
        int ret = INT_MAX/2;
        for (int p=0; p<=9; p++)
            ret = min(ret, dp[n-1][p]);
        return ret;        
    }
};
