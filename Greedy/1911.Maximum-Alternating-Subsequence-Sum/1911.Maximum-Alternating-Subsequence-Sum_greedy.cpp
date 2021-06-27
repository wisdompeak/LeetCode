typedef long long ll;
class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) 
    {
        ll ret = 0;
        int i = 0;
        while (i<nums.size())
        {
            if (i+1<nums.size() && nums[i]>nums[i+1])            
                ret+= nums[i] - nums[i+1];
            i++;
        }

        ret += nums.back();

        return ret;
    }
};
