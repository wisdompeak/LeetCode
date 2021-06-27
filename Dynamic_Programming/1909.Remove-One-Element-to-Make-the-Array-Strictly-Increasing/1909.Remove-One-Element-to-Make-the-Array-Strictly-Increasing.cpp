class Solution {
public:
    bool canBeIncreasing(vector<int>& nums) 
    {
        int n = nums.size();
        
        nums.insert(nums.begin(), INT_MIN); // nums[1:n]
        vector<int>dp0(n+1);
        vector<int>dp1(n+1);
        
        dp0[0] = 0;
        dp1[0] = 0;
        
        for (int i=1; i<=n; i++)
        {
            if (nums[i]>nums[i-1])
                dp0[i] = dp0[i-1] + 1;
            else     
                dp0[i] = 1;
            
            dp1[i] = 0;
            if (nums[i]>nums[i-1])
                dp1[i] = max(dp1[i], dp1[i-1] + 1);            
            if (i>=2 && nums[i]>nums[i-2])
                dp1[i] =  max(dp1[i], dp0[i-2] + 1);  
            
            if (dp0[i]>=n-1 || dp1[i]>=n-1)
                return true;
        }
        
        return false;
    }
};
