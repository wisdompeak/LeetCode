class Solution {
public:
    int tallestBillboard(vector<int>& rods) 
    {
        int N = rods.size();
        int B = 5000;
        vector<int>dp(B*2+1,-1);
        dp[B] = 0;
        
        for (auto x: rods)
        {
            auto dp_temp = dp;
            for (int diff=-B; diff<B; diff++)
            {
                int j = diff+B;
                if (dp_temp[j]==-1) continue;
                                
                if (diff+x<B) dp[j+x] = max(dp[j+x],dp_temp[j]+x);
                if (diff-x>=-B) dp[j-x] = max(dp[j-x],dp_temp[j]);
            }            
        }
        return dp[B];
    }
};
