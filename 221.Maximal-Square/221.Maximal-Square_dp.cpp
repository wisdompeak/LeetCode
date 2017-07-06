class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) 
    {
        int M=matrix.size();
        if (M==0) return 0;
        int N=matrix[0].size();
        auto dp=vector<vector<int>>(M+1,vector<int>(N+1,0));
        int result=0;
        
        for (int i=1; i<=M; i++)
            for (int j=1; j<=N; j++)
            {
                if (matrix[i-1][j-1]=='0')
                    dp[i][j]=0;
                else
                {
                    int temp=min(dp[i-1][j],dp[i][j-1]);
                    temp = min(temp,dp[i-1][j-1]);
                    dp[i][j]=temp+1;
                    result=max(result,dp[i][j]*dp[i][j]);
                }
            }
        
        return result;
    }
};
