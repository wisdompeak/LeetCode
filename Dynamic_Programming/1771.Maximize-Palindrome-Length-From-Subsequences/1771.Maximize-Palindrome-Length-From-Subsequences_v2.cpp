class Solution {    
public:
    int longestPalindrome(string word1, string word2) 
    {
        int m = word1.size(), n = word2.size();        
        int t = m + n;
        string word = word1+word2;
                
        int ret = 0;
        auto dp = vector<vector<int>>(t, vector<int>(t,0));

        for (int i=0; i<t; i++)
            dp[i][i] = 1;
        
        for (int len=2; len<=t; len++)
            for (int i=0; i+len-1<t; i++)
            {
                int j = i+len-1;
                if (word[i]==word[j])
                {
                    dp[i][j] = dp[i+1][j-1]+2;
                    if (i<m && j>=m)
                        ret = max(ret, dp[i][j]);
                }                    
                else
                    dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
            }                
        return ret;
    }
};
