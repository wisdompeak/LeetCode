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
                int a = s[i]-'a';
                int b = s[j]-'a';
                if (s[i]==s[j])
                {
                    for (int kk=0; kk<26; kk++)
                    {
                        if (a != kk)
                            dp[i][j][a] = max(dp[i][j][a], dp[i+1][j-1][kk]+2);
                    }
                    for (int k=0; k<26; k++)
                    {
                        if (a != k)
                            dp[i][j][k] = dp[i+1][j-1][k];
                    }
                }
                else
                {
                    dp[i][j][a] = dp[i][j-1][a];
                    dp[i][j][b] = dp[i+1][j][b];
                    for (int k=0; k<26; k++)
                    {
                        if (k!=a && k!=b)
                            dp[i][j][k] = dp[i+1][j-1][k];
                    }
                }
            }
        
        int ret = 0;
        for (int k=0; k<26; k++)
            ret = max(ret, dp[0][n-1][k]);
        return ret;        
    }
};
