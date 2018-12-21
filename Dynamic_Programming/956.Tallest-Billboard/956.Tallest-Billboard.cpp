class Solution {
public:
    int tallestBillboard(vector<int>& rods) 
    {
        int N = rods.size();
        int B = 5000;
        vector<int>dp(B*2+1,-1);
        dp[B] = 0;
        
        for (int i=0; i<N; i++)
        {
            auto dp_temp = dp;
            for (int diff=-B; diff<B; diff++)
            {
                int j = diff+B;
                if (dp_temp[j]==-1) continue;
                                
                if (diff+rods[i]<B) dp[j+rods[i]] = max(dp[j+rods[i]],dp_temp[j]+rods[i]);
                if (diff-rods[i]>=-B) dp[j-rods[i]] = max(dp[j-rods[i]],dp_temp[j]);
            }            
        }
        return dp[B];
    }
};
