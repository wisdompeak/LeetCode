class Solution {
public:
    int strangePrinter(string s) 
    {
        int dp[110][110];
        int n = s.length();
        if (n == 0) return 0;
        
        for (int i = 0; i < n; ++i) 
            dp[i][i] = 1;        

        for (int len=2; len<=n; len++)
         for (int i=0; i<=n-len; i++)
         {
             dp[i][i+len-1]=dp[i][i+len-2]+1;
             for (int k=i; k<i+len-1; k++)
             {
                 if (s[k]==s[i+len-1])
                     dp[i][i+len-1]=min(dp[i][i+len-1], dp[i][k]+dp[k+1][i+len-2]);
             }
         }
        
        return dp[0][n-1];
    }
};
