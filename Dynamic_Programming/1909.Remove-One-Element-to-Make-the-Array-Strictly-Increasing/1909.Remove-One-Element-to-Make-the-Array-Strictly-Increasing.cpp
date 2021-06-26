class Solution {
public:
    bool canBeIncreasing(vector<int>& nums) 
    {
        int n = nums.size();        
        vector<int>dp0(n);
        vector<int>dp1(n);
        
        dp0[0] = 1;
        dp1[0] = 0;
        
        for (int i=1; i<n; i++)
        {
            dp0[i] = nums[i]>nums[i-1] ? (dp0[i-1] + 1) : 1;
            
            if (i>=2 && nums[i]>nums[i-2])
                dp1[i] = max(dp1[i], dp0[i-2] + 1);
            if (nums[i]>nums[i-1])
                dp1[i] = max(dp1[i], dp1[i-1] + 1);
                        
            if (dp0[i]>=n-1 || dp1[i]>=n-1) return true;
        }
        
        return false;
        
    }
};
