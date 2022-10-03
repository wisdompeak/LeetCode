class Solution {
    int lcs[4001][4001];
    int dp[4001];
public:
    int deleteString(string s) 
    {
        int n = s.size();        
        if (equal(s.begin() + 1, s.end(), s.begin()))
            return n;

        for (int i=n-1; i>=0; i--)
            for (int j=n-1; j>=i+1; j--)
            {
                if (s[i]==s[j])
                    lcs[i][j] = lcs[i+1][j+1]+1;
            }

        
        for (int i=n-1; i>=0; i--)
        {
            dp[i] = 1;
            for (int j=i+1; j<n; j++)
            {
                if (lcs[i][j]>=j-i)
                {
                    dp[i] = max(dp[i], dp[j]+1);
                }
            }
        }
        return dp[0];
    }
};
