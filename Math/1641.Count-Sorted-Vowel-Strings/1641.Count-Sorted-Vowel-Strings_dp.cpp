class Solution {
    int dp[51][5];
public:
    int countVowelStrings(int n) 
    {
        for (int k=0; k<5; k++)
            dp[1][k] = 1;
        
        for (int i=2; i<=n; i++)
            for (int j=0; j<5; j++)
            {
                for (int k=0; k<=j; k++)
                    dp[i][j] += dp[i-1][k];
            }
            
        int ret = 0;
        for (int k=0; k<5; k++)
            ret += dp[n][k];
        return ret;        
    }
};
