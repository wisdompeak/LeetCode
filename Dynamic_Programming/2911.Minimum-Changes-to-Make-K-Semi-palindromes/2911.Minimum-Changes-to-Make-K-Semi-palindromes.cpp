class Solution {
public:
    int helper(string&s, int a, int b, int d, int r)
    {
        int i = a + r;
        int j = b - (d-r) + 1;
        int count = 0;
        while (i<j)
        {
            count += (s[i]!=s[j]);
            i+=d;
            j-=d;
        }
        return count;
    }

    int minimumChanges(string s, int k) 
    {
        int dp[205][205];
        int range[205][205];

        int n = s.size();

        for (int i=0; i<n; i++)
            for (int j=i; j<n; j++)
            {
                int len = j-i+1;
                range[i][j] = INT_MAX/2;
                for (int d = 1; d<=len/2; d++)
                {
                    if (len%d!=0) continue;
                    int sum = 0;
                    for (int r = 0; r<d; r++)
                        sum += helper(s, i, j, d, r);
                    range[i][j] = min(range[i][j], sum);
                }
            }

        for(int i=0; i<n; i++)
            dp[i][1] = range[0][i];

        for (int i=0; i<n; i++)
            for (int p=2; p<=k; p++)
                {
                    dp[i][p] = INT_MAX/2;
                    for (int j=0; j<i; j++)
                        dp[i][p] = min(dp[i][p], dp[j][p-1] + range[j+1][i]);
                }
        return dp[n-1][k];

        
    }
};
