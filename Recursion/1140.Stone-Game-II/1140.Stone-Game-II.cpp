class Solution {
    int dp[101][101];    
    int sufsum[101];
public:
    int stoneGameII(vector<int>& piles) 
    {
        int n = piles.size();
        for (int i=0; i<=100; i++)
            for (int j=0; j<=100; j++)
                dp[i][j] = 0;
        sufsum[n] = 0;
        for (int i=n-1; i>=0; i--)
            sufsum[i] = sufsum[i+1]+piles[i];
        return solve(0, 1, piles);
    }

    int solve(int i, int M, vector<int>& piles)
    {
        if (i==piles.size()) return 0;
        if (dp[i][M]!=0) return dp[i][M];

        for (int x=1; x<=2*M; x++)
        {
            if (i+x>piles.size()) break;
            dp[i][M] = max(dp[i][M], sufsum[i] - solve(i+x, max(x,M), piles));
        }
        return dp[i][M];
    }
};
