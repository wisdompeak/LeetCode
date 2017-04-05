class Solution {
public:
    int splitArray(vector<int>& nums, int m) 
    {
        int n=nums.size();
        auto dp=vector<vector<long>>(n+1,vector<long>(m+1,INT_MAX));
        
        auto sum=vector<long>(n+1,0);
        for (int i=1; i<=n; i++)
            sum[i]=sum[i-1]+nums[i-1];
        
        dp[0][0]=0;
        
        for (int i=1; i<=n; i++)
        {
            int MaxDivde = min(m,i);
            
            for (int k=1; k<=MaxDivde; k++)
            {
                if (k==1) 
                {
                    dp[i][k]=sum[i];
                    continue;
                }
                    
                for (int j=i-1; j>=k-1; j--)
                {
                    long partSum = sum[i]-sum[j];
                    if (partSum > dp[i][k]) break;
                    dp[i][k] = min(dp[i][k], max(partSum,dp[j][k-1]));
                }
            }
        }
        
        return dp[n][m];
        
    }
};
