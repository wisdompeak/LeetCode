class Solution {
    int dp[13][4096];
public:
    int selfDivisiblePermutationCount(int n) 
    {
        int state = 0;
        dp[0][0] = 1;
        for (int i=1; i<=n; i++)
            for (int state = 0; state<(1<<n); state++)
            {
                for (int d=1; d<=n; d++)
                {
                    if (gcd(d,i)!=1) continue;
                    if (((state>>(d-1))&1)==0) continue;
                    dp[i][state] += dp[i-1][state-(1<<(d-1))];
                }
            }
        return dp[n][(1<<n)-1];
    }
};
