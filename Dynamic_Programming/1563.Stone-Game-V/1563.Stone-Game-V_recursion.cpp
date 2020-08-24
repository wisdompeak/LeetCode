class Solution {
    int dp[501][501];
    int presum[501];
public:
    int stoneGameV(vector<int>& stoneValue) 
    {
        int n = stoneValue.size();
        stoneValue.insert(stoneValue.begin(),0);
        presum[0] = 0;
        for (int i=1; i<=n; i++)
            presum[i] = presum[i-1]+stoneValue[i];
        
        for (int i=0; i<501; i++)
            for (int j=0; j<501; j++)
                dp[i][j] = 0;
        
        for (int i=1; i<=n-1; i++)
            dp[i][i+1] = min(stoneValue[i], stoneValue[i+1]);
        
        return solve(1,n);
    }
    
    int solve (int i, int j)
    {   
        if (dp[i][j]!=0)
            return dp[i][j];
        if (i>=j)
            return 0;
        
        for (int k=i; k<j; k++)
        {
            int leftsum = presum[k] - presum[i-1];
            int rightsum = presum[j] - presum[k];
            if (leftsum > rightsum)
                dp[i][j] = max(dp[i][j], rightsum + solve(k+1,j));
            else if (leftsum < rightsum)
                dp[i][j] = max(dp[i][j], leftsum + solve(i,k));
            else
                dp[i][j] = max(dp[i][j], leftsum + max(solve(i,k), solve(k+1,j)));
        }
        
        return dp[i][j];
    }
};
