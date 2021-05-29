class Solution {
public:
    int minimumXORSum(vector<int>& nums1, vector<int>& nums2) 
    {
        int m = nums1.size();
        vector<int>dp(1<<m, INT_MAX/2);
        vector<int>dp2(1<<m);
        dp[0] = 0;
        
        for (int i=0; i<m; i++)
        {
            dp2 = dp;
            
            for (int state = 1; state < (1<<m); state++)
            {
                dp[state] = INT_MAX/2;
                for (int j=0; j<m; j++)
                {
                    if ((state>>j)&1)
                    {
                        dp[state] = min(dp[state], dp2[state-(1<<j)]+(nums1[j]^nums2[i]));
                    }                        
                }
            }            
        }
        return dp[(1<<m)-1];
    }
};
