class Solution {
    int dp[1005][1005][6];
public:
    int maxTastiness(vector<int>& price, vector<int>& tastiness, int maxAmount, int maxCoupons) 
    {
        int ret = 0;
        dp[0][0][0] = 0;
        if (price[0]<=maxAmount)
        {
            dp[0][price[0]][0] = tastiness[0];
            ret = tastiness[0];
        }
        if (price[0]/2<=maxAmount && 1<=maxCoupons)
        {
            dp[0][price[0]/2][1] = tastiness[0];
            ret = tastiness[0];
        }
        
        for (int i=1; i<price.size(); i++)
            for (int j=0; j<=maxAmount; j++)
                for (int k=0; k<=maxCoupons; k++)
                {
                    dp[i][j][k] = dp[i-1][j][k];
                    if (j>=price[i])
                        dp[i][j][k] = max(dp[i][j][k], dp[i-1][j-price[i]][k] + tastiness[i]);
                    if (j>=price[i]/2 && k>=1)
                        dp[i][j][k] = max(dp[i][j][k], dp[i-1][j-price[i]/2][k-1] + tastiness[i]);
                    
                    ret = max(ret, dp[i][j][k]);
                }
        
        return ret;
        
        
    }
};
