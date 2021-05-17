class Solution {
    long dp[205][205];
    long M = 1e9+7;
public:
    int numPermsDISequence(string s) 
    {
        int n = s.size();
        s = "#"+s;  
        dp[0][0] = 1;      
        for (int i=1; i<=n; i++)
            for (int j=0; j<=i; j++)
            {
                if (s[i]=='I')
                {
                    for (int k=0; k<j; k++)
                        dp[i][j] = (dp[i][j] + dp[i-1][k]) % M;
                }
                else
                {
                    for (int k=i-1; k>=j; k--)
                        dp[i][j] = (dp[i][j] + dp[i-1][k]) % M;
                }
            }

        long ret = 0;
        for (int j=0; j<=n; j++)
            ret = (ret + dp[n][j]) % M;
        return ret;
    }
};
