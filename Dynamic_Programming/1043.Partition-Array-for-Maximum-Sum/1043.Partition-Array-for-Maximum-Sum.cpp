class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& A, int K) 
    {
        int N = A.size();
        A.insert(A.begin(),0);
        vector<int>dp(N+1,0); //dp[1]~dp[N]:  dp[0]
        
        for (int i=1; i<=N; i++)
        {
            // update dp[i]
            int MAX = INT_MIN;
            for (int j=i; j>=max(i-K+1,1); j--)
            {
                MAX = max(MAX, A[j]);
                dp[i] = max(dp[i], dp[j-1] + MAX*(i-j+1));

            }
        }
        
        return dp[N];
        
    }
};
