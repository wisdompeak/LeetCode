class Solution {
public:
    int maxSumAfterOperation(vector<int>& nums) 
    {
        int a = 0, b = 0;
        int ret = 0;
        for (auto x: nums)
        {
            int a0 = a, b0 = b;
            a = max(a0+x, x);
            b = max(b0+x, x);            
            b = max(b, a0+x*x);
            b = max(b, x*x);
            
            ret = max(ret, a);
            ret = max(ret, b);
        }
        return ret;
        
    }
};
