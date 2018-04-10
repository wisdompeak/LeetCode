class Solution {
public:
    double largestSumOfAverages(vector<int>& A, int K) 
    {
        int N=A.size();
        
        auto dp=vector<vector<double>>(N,vector<double>(K+1,0));
        
        double sum=0;
        for (int i=0; i<N; i++)
        {
            sum+=A[i];
            dp[i][1]=sum*1.0/(i+1);
        }
        
        for (int k=2; k<=K; k++)
        {
            for (int i=k-1; i<N; i++)
            {
                int sum = 0;
                for (int j=i; j>=k-1; j--)
                {
                    sum+=A[j];
                    dp[i][k]=max(dp[i][k], sum*1.0/(i-j+1)+dp[j-1][k-1]);
                }
            }
        }
        
        return dp[N-1][K];
    }
};
