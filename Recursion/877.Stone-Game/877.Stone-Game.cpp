class Solution {
    int dp[501][501];
public:
    bool stoneGame(vector<int>& piles) 
    {
        int myBest = solve(0, piles.size()-1, piles);
        int total = accumulate(piles.begin(), piles.end(), 0);
        return (myBest>total-myBest);
    }

    int solve(int a, int b, vector<int>& piles)
    {
        if (a==b) return piles[a];
        if (dp[a][b]!=0) return dp[a][b];
        dp[a][b] = max(piles[a]+solve(a+1,b, piles), piles[b]+solve(a,b-1, piles));
        return dp[a][b];
    }
};
