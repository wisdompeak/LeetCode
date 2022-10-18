class Solution {
    int dp[101][101];
    int suf[101];
    
public:
    int stoneGameII(vector<int>& piles) 
    {
        int n = piles.size();
        suf[n] = 0;
        for (int i=n-1; i>=0; i--)
            suf[i] = suf[i+1]+piles[i];
        
        return solve(0, 1, piles);
    }
    
    int solve(int i, int M, vector<int>& piles)
    {
        if (i==piles.size()) return 0;
        if (dp[i][M]!=0)
            return dp[i][M];
        
        int sum = 0;
        for (int x=1; x<=2*M; x++)
        {
            if (i+x-1>=piles.size()) break;
            sum += piles[i+x-1];            
            dp[i][M] = max(dp[i][M], sum + suf[i+x] - solve(i+x, max(x,M), piles));
        }
        return dp[i][M];
    }
};
