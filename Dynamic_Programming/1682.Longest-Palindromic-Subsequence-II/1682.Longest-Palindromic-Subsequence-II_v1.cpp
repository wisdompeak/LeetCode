class Solution {
    int dp[250][250][26];
public:
    int longestPalindromeSubseq(string s) 
    {
        int n = s.size();
        for (int i=0; i+1<n; i++)
        {
            if (s[i]==s[i+1])
                dp[i][i+1][s[i]-'a'] = 2;
        }
        
        for (int len=3; len<=n; len++)
            for (int i=0; i+len-1<n; i++)
            {
                int j = i+len-1;
                for (int k=0; k<26; k++)
                {
                    if (s[i]==s[j] && s[i]=='a'+k)
                    {
                        for (int kk=0; kk<26; kk++)
                            if (kk!=k)
                                dp[i][j][k] = max(dp[i][j][k], dp[i+1][j-1][kk]+2);
                    }
                    dp[i][j][k] = max(dp[i][j][k], dp[i+1][j][k]);
                    dp[i][j][k] = max(dp[i][j][k], dp[i][j-1][k]);
                }
            }
        
        int ret = 0;
        for (int k=0; k<26; k++)
            ret = max(ret, dp[0][n-1][k]);
        return ret;        
    }
};
