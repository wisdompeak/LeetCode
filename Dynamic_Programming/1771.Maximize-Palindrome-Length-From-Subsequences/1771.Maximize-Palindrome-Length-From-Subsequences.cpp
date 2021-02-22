class Solution {    
public:
    vector<vector<int>> isPalindrome(string& word, int n)
    {        
        auto dp = vector<vector<int>>(n+1, vector<int>(n+1));
        for (int i=1; i<=n; i++)
            dp[i][i] = 1;
        for (int len=2; len<=n; len++)
            for (int i=1; i+len-1<=n; i++)
            {
                int j = i+len-1;
                if (word[i]==word[j])
                    dp[i][j] = dp[i+1][j-1]+2;
                else
                    dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
            }
        return dp;
    }

    int longestPalindrome(string word1, string word2) 
    {
        int m = word1.size(), n = word2.size();        
        reverse(word2.begin(), word2.end());
        word1 = "#"+word1;
        word2 = "#"+word2;
                        
        auto dp1 = isPalindrome(word1, m);
        auto dp2 = isPalindrome(word2, n);       
        
        int ret = 0;
        auto dp = vector<vector<int>>(m+1, vector<int>(n+1,0));
        
        for (int i=1; i<=m; i++)
            for (int j=1; j<=n; j++)
            {
                if (word1[i]==word2[j])
                {
                    dp[i][j] = dp[i-1][j-1]+1;
                    ret = max(ret, dp[i][j]*2 + max(i+1<=m ? dp1[i+1][m]:0, j+1<=n ? dp2[j+1][n]:0));
                }                    
                else
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }                
        return ret;
    }
};
