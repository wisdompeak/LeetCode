class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) 
    {
        sort(nums.begin(), nums.end());

        long count = 0;
        int j = 0;
        int ret = 1;
        for (int i=1; i<nums.size(); i++)
        {
            count += (long)(i-j)*(long)(nums[i]-nums[i-1]);
            while (count > k)
            {
                count-= nums[i]-nums[j];
                j++;
            }
            ret = max(ret, i-j+1);
        }
        return ret;

    }
};
