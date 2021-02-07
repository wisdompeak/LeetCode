class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) 
    {
        int mx = 0, mn = 0;
        int ret = 0;
        for (int x: nums)
        {            
            mx = max(mx + x, x);
            mn = min(mn + x, x);
            ret = max(ret, abs(mx));
            ret = max(ret, abs(mn));
        }
        return ret;
    }
};
