class Solution {    
    int presum[501];
    int dp[501][501];
    vector<int>stoneValue;
public:
    int stoneGameV(vector<int>& stoneValue) 
    {
        int n = stoneValue.size();              
        stoneValue.insert(stoneValue.begin(),0);     
        this->stoneValue = stoneValue;             
        presum[0] = 0;
        for (int i=1; i<=n; i++)
            presum[i] = presum[i-1]+stoneValue[i];

        for (int i=0; i<=n; i++)
            for (int j=0; j<=n; j++)
                dp[i][j] = 0;

        return solve(1,n);
    }

    int solve (int i, int j)
    {
        if (i>=j) return 0;
        if (i+1==j)
            return min(stoneValue[i], stoneValue[i+1]);
        if (dp[i][j]!=0)
            return dp[i][j];
        
        for (int k=i; k<j; k++)
        {
            int leftSum = presum[k]-presum[i-1];
            int rightSum = presum[j]-presum[k];

            if (leftSum<rightSum)
                dp[i][j] = max(dp[i][j], solve(i,k)+leftSum);
            else if (leftSum==rightSum)
                dp[i][j] = max(dp[i][j], max(solve(i,k),solve(k+1,j))+rightSum);
            else if (leftSum>rightSum)                    
                dp[i][j] = max(dp[i][j], solve(k+1,j)+rightSum);                                            
        }
        
        return dp[i][j];
    }
};
