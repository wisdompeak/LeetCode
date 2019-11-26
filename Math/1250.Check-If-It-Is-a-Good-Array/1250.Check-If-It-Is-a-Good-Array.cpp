class Solution {
public:
    bool isGoodArray(vector<int>& nums) 
    {
        int k = nums[0];
        for (int i=1; i<nums.size(); i++)
        {
            k = gcd(k,nums[i]);
            if (k==1) return true;
        }
        return k==1;
    }
};
