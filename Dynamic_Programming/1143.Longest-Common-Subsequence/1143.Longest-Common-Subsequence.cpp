class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) 
    {
        int m = text1.size();
        int n = text2.size();
        text1 = "#"+text1;
        text2 = "#"+text2;
        
        auto dp = vector<vector<int>>(m+1,vector<int>(n+1,0));
        
        for (int i=1; i<=m; i++)
            for (int j=1; j<=n; j++)
            {
                if (text1[i]==text2[j])
                    dp[i][j] = dp[i-1][j-1]+1;
                else
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        
        return dp[m][n];
    }
};
