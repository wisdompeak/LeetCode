class Solution {
public:
    int minDeletionSize(vector<string>& A) 
    {
        int N = A[0].size();
        
        vector<int>dp(N,1);
        for (int i=1; i<N; i++)
            for (int j=0; j<i; j++)
            {
                if (checkLarger(i,j,A))
                    dp[i]=max(dp[i],dp[j]+1);
            }
        int result = 0;
        for (int i=0; i<N; i++)
            result = max(result,dp[i]);
        return N-result;
    }
    
    bool checkLarger(int x, int y, vector<string>&A)
    {
        int M = A.size();
        for (int i=0; i<M; i++)
        {
            if (A[i][x]<A[i][y])
                return false;
        }
        return true;
    }
};
