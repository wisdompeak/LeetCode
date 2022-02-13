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
        
        for (int state = 1; state < m; state++)
        {
            int i = 0;
            int temp = state;
            while (temp>0)
            {
                i+=temp%3;
                temp/=3;
            }
            if (i>n) continue;
                        
            for (int j=0; j<numSlots; j++)
            {
                if (filled(state, j)>=1)                    
                {                    
                    dp[i][state] = max(dp[i][state], dp[i-1][state - pow(3,j)] + (nums[i]&(j+1)));                     
                }
                    
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
