class Solution {
public:
    int longestPalindromeSubseq(string s) 
    {
        int N = s.size();
        auto dp = vector<vector<int>>(N,vector<int>(N,0));        
        
        for (int len=1; len<=N; len++)
            for (int i=0; i<=N-len; i++)
            {
                int j = i+len-1;
                if (len==1)
                    dp[i][j] = 1;
                else
                    dp[i][j] = (s[i]==s[j])? dp[i+1][j-1]+2:max(dp[i][j-1],dp[i+1][j]);
            }
        return dp[0][N-1];
    }
};
