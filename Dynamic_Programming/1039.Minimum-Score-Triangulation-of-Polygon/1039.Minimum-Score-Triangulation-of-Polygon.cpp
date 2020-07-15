class Solution {
public:
    int minScoreTriangulation(vector<int>& A) 
    {
        int N = A.size();
        auto dp = vector<vector<int>>(N,vector<int>(N,INT_MAX/3));
        
        for (int i=0; i<N-1; i++)
            dp[i][i+1] = 0;
        
        for (int len=3; len<=N; len++)
            for (int i=0; i+len-1<N; i++)
            {
                int j = i+len-1;
                for (int k=i+1; k<=j-1; k++)
                    dp[i][j] = min(dp[i][j], dp[i][k]+dp[k][j]+A[i]*A[j]*A[k]);
            }
        return dp[0][N-1];
    }
};
