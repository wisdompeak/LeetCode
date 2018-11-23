class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) 
    {
        int s = 0;
        for (auto n:nums) s = s^n;  // i.e. a^b
        int t = s^(s&(s-1)); // only keep the rightmost set bit
        int a = 0, b = 0;
        for (auto n:nums)
        {
            if (n&t) a = a^n;
            else b = b^n;
        }
        return {a,b};        
    }
};
