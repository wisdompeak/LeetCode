class Solution {
public:
    int palindromePartition(string s, int k) 
    {
        int n = s.size();
        s = "#"+s;
        int K = k;

        auto count = vector<vector<int>>(n+1, vector<int>(n+1,0));
        for (int i=1; i<=n; i++)
            count[i][i] = 0;
        for (int len=2; len <=n; len++)
            for (int i=1; i+len-1<=n; i++)
            {
                int j = i+len-1;
                if (s[i]==s[j])
                    count[i][j] = count[i+1][j-1];
                else
                    count[i][j] = count[i+1][j-1]+1;
            }

        auto dp = vector<vector<int>>(n+1, vector<int>(K+1,INT_MAX/2));
        dp[0][0] = 0;
        for (int i=1; i<=n; i++)
            for (int k=1; k<=min(i,K); k++)
            {
                dp[i][k] = INT_MAX;
                for (int j=k; j<=i; j++)
                {
                    dp[i][k] = min(dp[i][k], dp[j-1][k-1] + count[j][i]); 
                }
            }

        return dp[n][K];
    }
};
