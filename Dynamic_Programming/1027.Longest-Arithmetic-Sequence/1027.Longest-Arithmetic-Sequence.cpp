class Solution {
public:
    int longestArithSeqLength(vector<int>& A) 
    {
        vector<unordered_map<int,int>>dp(A.size());
        int result = 1;
        for (int i=0; i<A.size(); i++)
        {
            for (int j=0; j<i; j++)
            {
                int diff = A[i]-A[j];
                if (dp[j][diff]==0)
                    dp[i][diff] = 2;
                else
                    dp[i][diff] = dp[j][diff]+1;
                result = max(result, dp[i][diff]);
            }
        }
        return result;
    }
};
