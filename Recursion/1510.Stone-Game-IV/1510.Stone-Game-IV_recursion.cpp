class Solution {
    int dp[100001];
public:
    bool winnerSquareGame(int n) 
    {
        for (int i=1; i<=n; i++)
            dp[i] = -1;
        return solve(n);
    }

    bool solve(int n)
    {
        if (dp[n]!=-1)
            return dp[n];

        for (int i=1; i*i<=n; i++)
        {
            if (solve(n-i*i)==0)
            {
                dp[n] = 1;
                return true;
            }
        }
        dp[n] = 0;
        return false;
    }
};
