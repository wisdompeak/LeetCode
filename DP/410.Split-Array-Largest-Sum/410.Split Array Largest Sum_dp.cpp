class Solution {
public:
    int splitArray(vector<int>& nums, int m) 
    {
        int n=nums.size();
        auto dp = vector<vector<int>>(n+1,vector<int>(m+1,0));
        
        int sum=0;
        for (int i=1; i<=n; i++)
        {
            sum+=nums[i-1];
            dp[i][1]=sum;
        }
        
        for (int i=1; i<=n; i++)
         for (int k=2; k<=m; k++)
         {
             int temp = INT_MAX;
             for (int j=k-1; j<=i-1; j++)
             {
                 temp = min(temp, max(dp[j][k-1],dp[i][1]-dp[j][1]));
             }
             dp[i][k]=temp;
        }
        
        return dp[n][m]; 
    }
};
