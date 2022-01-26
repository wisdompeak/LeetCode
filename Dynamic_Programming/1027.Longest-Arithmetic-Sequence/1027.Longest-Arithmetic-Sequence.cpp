class Solution {
public:
    int longestArithSeqLength(vector<int>& A) 
    {
        int n = A.size();
        int offset = 500;
        vector<vector<int>>dp(n,vector<int>(1001));
        int result = 1;
        for (int i=0; i<A.size(); i++)
        {
            for (int j=0; j<i; j++)
            {
                int diff = A[i]-A[j];
                if (dp[j][diff+offset]==0)
                    dp[i][diff+offset] = 2;
                else
                    dp[i][diff+offset] = dp[j][diff+offset]+1;
                result = max(result, dp[i][diff+offset]);
            }
        }
        return result;
    }
};
