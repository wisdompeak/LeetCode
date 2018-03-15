class Solution {
public:
    int longestPalindromeSubseq(string s) 
    {
        int N=s.size();
        auto dp=vector<vector<int>>(N,vector<int>(N,0));
        
        for (int i=0; i<N; i++)
            dp[i][i]=1;
        
        for (int i=0; i<N-1; i++)
        {
            if (s[i]==s[i+1])
                dp[i][i+1]=2;
            else
                dp[i][i+1]=1;
        }
        
        for (int len=3; len<=N; len++)
        {
            for (int i=0; i<=N-len; i++)
            {
                if (s[i]==s[i+len-1])
                    dp[i][i+len-1] = 2+dp[i+1][i+len-2];
                else
                    dp[i][i+len-1] = max(dp[i+1][i+len-1],dp[i][i+len-2]);                
            }
        }
        return dp[0][N-1];
    }
};
