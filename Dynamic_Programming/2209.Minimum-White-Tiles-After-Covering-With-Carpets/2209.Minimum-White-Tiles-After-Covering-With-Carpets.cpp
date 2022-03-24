class Solution {    
    int dp[1001][1001];
public:
    int minimumWhiteTiles(string floor, int numCarpets, int carpetLen) 
    {
        int n = floor.size();
        floor = "#"+floor;        
        
        dp[0][0] = 0;                
        for (int i=1; i<=n; i++)
            for (int j=0; j<=numCarpets; j++)
            {        
                dp[i][j] = INT_MAX/2;
                dp[i][j] = min(dp[i][j], dp[i-1][j] + (floor[i]=='1'));                               
                if (j>=1)
                    dp[i][j] = min(dp[i][j], i>=carpetLen ? dp[i-carpetLen][j-1]:0);
            }
        
        return dp[n][numCarpets];
        
    }
};
