class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) 
    {
        int m = matrix.size();
        int n = matrix[0].size();
        auto dp = vector<vector<int>>(m,vector<int>(n,0));

        int count = 0;
        for (int i=0; i<m; i++)
        {
            dp[i][0] = (matrix[i][0]==1);
            count += (matrix[i][0]==1);
        }
            
        for (int j=1; j<n; j++)
        {
            dp[0][j] = (matrix[0][j]==1);
            count += (matrix[0][j]==1);
        }

        for (int i=1; i<m; i++)
            for (int j=1; j<n; j++)
            {
                if (matrix[i][j]==0) continue;
                int k = min(dp[i-1][j], dp[i][j-1]);
                k = min(k, dp[i-1][j-1]);
                k += 1;
                dp[i][j] = k;
                count += k;                
            }
        return count;

    }
};
