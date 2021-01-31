class Solution {
    int dp[2000][2000];
public:
    bool checkPartitioning(string s) 
    {
        int n = s.size();
        for (int i=0; i<n; i++)
            dp[i][i] = 1;
        for (int i=0; i+1<n; i++)
            if (s[i]==s[i+1])
                dp[i][i+1] = 1;
        
        
        for (int len = 3; len <= n; len ++) 
            for (int i=0; i+len-1<n; i++)
            {
                int j = i+len-1;
                if (s[i]==s[j])
                    dp[i][j] = dp[i+1][j-1];
                else
                    dp[i][j] = 0;
            }
        
        for (int i=0; i<n; i++)
            for (int j=i+2; j<n; j++)
            {
                if (dp[0][i] && dp[i+1][j-1] && dp[j][n-1])
                    return true;
            }
        return false;
    }
};
