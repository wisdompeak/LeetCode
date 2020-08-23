class Solution {
    int presum[501];
    int dp[501][501];
public:
    int stoneGameV(vector<int>& stoneValue) 
    {
        int n = stoneValue.size();
        stoneValue.insert(stoneValue.begin(),0);        
        
        presum[0] = 0;
        for (int i=1; i<=n; i++)
            presum[i] = presum[i-1]+stoneValue[i];                
        
        for (int i=1; i<=n; i++)
            for (int j=1; j<=n; j++)
                dp[i][j] = 0;
        
        for (int i=1; i<=n-1; i++)
            dp[i][i+1] = min(stoneValue[i], stoneValue[i+1]);        
        
        for (int len = 3; len <= n; len++)
        {
            for (int i=1; i+len-1<=n; i++)
            {
                int j = i+len-1;
                
                for (int k=i; k<j; k++)
                {
                    int leftSum = presum[k]-presum[i-1];
                    int rightSum = presum[j]-presum[k];

                    if (leftSum<rightSum)
                        dp[i][j] = max(dp[i][j], dp[i][k]+leftSum);
                    else if (leftSum==rightSum)
                        dp[i][j] = max(dp[i][j], max(dp[i][k],dp[k+1][j])+rightSum);
                    else if (leftSum>rightSum)                    
                        dp[i][j] = max(dp[i][j], dp[k+1][j]+rightSum);                                            
                }
            }
        }
        
        return dp[1][n];
        
    }
};
