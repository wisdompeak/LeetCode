using LL = long long;
class Solution {
public:
    long long maximumAlternatingSubarraySum(vector<int>& nums) 
    {
        LL ret = INT_MIN;
        LL curSum0 = INT_MIN;
        LL curSum1 = 0;
        
        for (LL x: nums)
        {
            LL curSum0_temp = curSum0;
            LL curSum1_temp = curSum1;
            curSum0 = max(curSum1_temp + x, x);
            curSum1 = curSum0_temp - x;
                        
            ret = max(ret, curSum0);
            ret = max(ret, curSum1);
        }        
        return ret;        
    }
};
