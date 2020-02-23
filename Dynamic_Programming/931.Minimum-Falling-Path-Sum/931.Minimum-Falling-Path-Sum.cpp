class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& A) 
    {
        auto dp = A;        // dp[i][j]: minimum sum of a falling path through A to (i,j)
        int m = A.size();
        int n = A[0].size();
        
        for (int j=0; j<n; j++)
            dp[0][j] = A[0][j];
        
        for (int i=1; i<m; i++)
            for (int j=0; j<n; j++)
            {
                dp[i][j] = INT_MAX;
                for (int k = j-1; k<=j+1; k++)
                {
                    if (k<0 || k>=n) continue;
                    dp[i][j] = min(dp[i][j],  dp[i-1][k]+A[i][j]);                    
                }                
            }
        int ret = INT_MAX;
        for (int j=0; j<n; j++)
            ret = min(ret, dp[m-1][j]);
        return ret;
        
    }
};
