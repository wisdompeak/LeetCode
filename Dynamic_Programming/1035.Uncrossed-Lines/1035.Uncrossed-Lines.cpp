class Solution {
public:
    int maxUncrossedLines(vector<int>& A, vector<int>& B) 
    {
        int m = A.size();
        int n = B.size();
        auto dp = vector<vector<int>>(m+1,vector<int>(n+1,0));
        A.insert(A.begin(),0);
        B.insert(B.begin(),0);
        
        dp[0][0] = 0;
        for (int i=1; i<=m; i++)
            for (int j=1; j<=n; j++)
            {
                if (A[i]==B[j])
                    dp[i][j] = dp[i-1][j-1]+1;
                else
                    dp[i][j] = max(dp[i][j-1], dp[i-1][j]);                    
            }
        return dp[m][n];
    }
};
