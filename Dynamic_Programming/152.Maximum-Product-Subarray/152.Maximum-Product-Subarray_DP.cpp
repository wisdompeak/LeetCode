using LL = long long;
class Solution {
public:
    int maxProduct(vector<int>& nums) 
    {
        int n = nums.size();        
        vector<LL>dp1(n);  // the max prod subarray ending at i
        vector<LL>dp2(n);  // the min prod subarray ending at i
        dp1[0] = nums[0];
        dp2[0] = nums[0];
        LL ret = nums[0];
        
        for (int i=1; i<n; i++)
        {
            dp1[i] = max(max(dp1[i-1] * nums[i], dp2[i-1] * nums[i]), (LL)nums[i]);
            dp2[i] = min(min(dp1[i-1] * nums[i], dp2[i-1] * nums[i]), (LL)nums[i]);

            dp1[i] = max((LL)INT_MIN, dp1[i]);
            dp2[i] = max((LL)INT_MIN, dp2[i]);
            dp1[i] = min((LL)INT_MAX, dp1[i]);
            dp2[i] = min((LL)INT_MAX, dp2[i]);

            ret = max(ret, dp1[i]);
        }
        return ret;        
    }
};
