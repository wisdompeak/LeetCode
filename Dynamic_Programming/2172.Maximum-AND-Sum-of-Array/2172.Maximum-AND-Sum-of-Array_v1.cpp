class Solution {    
public:
    int maximumANDSum(vector<int>& nums, int numSlots) 
    {
        int n = nums.size();
        nums.insert(nums.begin(), 0);
        int m = pow(3, numSlots);
        vector<vector<int>>dp(n+1, vector<int>(m, INT_MIN/2));
        dp[0][0] = 0;
        
        int ret = 0;
        for (int i=1; i<=n; i++)        
            for (int state = 0; state < m; state++)
            {
                for (int j=0; j<numSlots; j++)
                {
                    if (filled(state, j)>=1)                    
                        dp[i][state] = max(dp[i][state], dp[i-1][state - pow(3,j)] + (nums[i]&(j+1))); 
                }
                if (i==n)
                    ret = max(ret, dp[i][state]);
            }        
        
        return ret;
    }
    
    bool filled(int state, int k)
    {
        for (int i=0; i<k; i++)
            state/=3;
        return state%3;
    }
};
