class Solution {
public:
    double largestSumOfAverages(vector<int>& A, int K) 
    {
        int N = A.size();
        A.insert(A.begin(), 0);
        auto dp = vector<vector<double>>(N+1, vector<double>(K+1,0));
        
        dp[0][0] = 0;        
        for (int i=1; i<=N; i++)
            dp[i][0] = INT_MIN/2;        
        
        for (int i=1; i<=N; i++)
            for (int k=1; k<=min(i,K); k++)
            {
                double sum = 0;
                for (int j=i; j>=k; j--)
                {
                    sum += A[j];
                    dp[i][k] = max(dp[i][k], dp[j-1][k-1]+sum*1.0/(i-j+1));
                }
            }
        
        double ret = 0;
        for (int k=1; k<=K; k++)
            ret = max(ret, dp[N][k]);
        return ret;
    }
};
