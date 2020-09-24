class Solution {
public:
    int maxProduct(vector<int>& nums) 
    {        
        int n = nums.size();
        vector<long>dp1(n);
        vector<long>dp2(n);
        dp1[0] = nums[0];
        dp2[0] = nums[0];
        long ret =  nums[0];
        
        for (int i=1; i<n; i++)
        {            
            dp1[i] = max(max(dp1[i-1]*(long)nums[i], dp2[i-1]*(long)nums[i]),(long)nums[i]);            
            dp2[i] = min(min(dp1[i-1]*(long)nums[i], dp2[i-1]*(long)nums[i]),(long)nums[i]);            
            ret = max(ret,dp1[i]);
        }
        return ret;
    }
};
