class Solution {       
public:
    int longestNiceSubarray(vector<int>& nums) 
    {
        int count = 0;
        int j = 0;
        int ret = 0;
        for (int i=0; i<nums.size(); i++)
        {
            while (j<nums.size() && (count & nums[j]) == 0)
            {
                count = count + nums[j];
                j++;
            }
            ret = max(ret, j-i);
            count -= nums[i];
        }
        return ret;
    }
};
