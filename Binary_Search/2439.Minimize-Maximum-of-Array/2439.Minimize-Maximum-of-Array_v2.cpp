class Solution {
public:
    int minimizeArrayValue(vector<int>& nums) 
    {
        long long sum = 0;
        long long ret = 0;
        for (int i=0; i<nums.size(); i++)
        {
            sum += nums[i];
            ret = max(ret, sum%(i+1)==0? sum/(i+1): (sum/(i+1)+1));
        }
        return ret;
    }
};
